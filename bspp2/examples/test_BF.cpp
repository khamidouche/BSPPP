#include <iostream>
//#include <bsppp/bsppp.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

//#include "data.hpp"

#include "boost/multi_array.hpp"
#include <cassert>

#include <sys/time.h>
#include <omp.h>

////// get time function /////

 double get_time()  {

            //static int sec = -1;
            struct timeval tv;
            gettimeofday(&tv, NULL);
            //if (sec < 0) sec = tv.tv_sec;
            return (tv.tv_sec/* - sec*/) + 1.0e-6*tv.tv_usec;

                  }

/////////////////////////////




///// include data /////



#include<vector>
#include<iostream>
#include<algorithm>


#include <boost/serialization/version.hpp>
#include <boost/serialization/split_member.hpp>




template<class T>
class data
{
  private:
  void link ()
   {
   rows[0]=&data_[0];
   for(int i=1;i<H;i++)
      rows[i]= rows[i-1]+W;
   }

  void swap(data<T> & src)
   {
     std::swap(H,src.H);
     std::swap(W,src.W);
     std::swap(rows,src.rows);
     std::swap(data_,src.data_);
    }


  public:
 data() /*:H(0),W(0),data_(0), rows(0) */{}
 data(int h,int w) : H(h), W(w)
 {

   rows.resize(H);
   data_.resize(H*W);
   link();


 }

//~data() { printf("deleting %x",(void*)(this)); }

 data(const data& A) {
   H=A.H;
   W=A.W;
   rows.resize(H);
   data_ = A.data_;
   link();
   }

  void resize (int h,int w)
   {
     H=h; W=w;
     rows.resize(H);
     data_.resize(H*W);
     link();

    }


  data<T>& operator = (data<T> src)
  {

    swap(src);
    return *this;
  }



 T const&  operator()(int i, int j)const { return rows[i][j];}
 T      &  operator()(int i, int j)      { return rows[i][j];}

 size_t size() const {return data_.size();}
 T* origin()   {return &data_[0];}
 T const* origin() const  {return &data_[0];}

friend class boost::serialization::access;

template <class Archive  >
void save(Archive& ar, const unsigned int version) const
{
   ar & H;
   ar & W;
   ar & data_;
}
template <class Archive >
void load(Archive &ar, const unsigned int version)
{
  int h,w;
  ar & h;
  ar & w;
  resize(h,w);
  ar & data_;


}

 BOOST_SERIALIZATION_SPLIT_MEMBER()


 private:
 int H,W;
 std::vector<T*> rows;
 std::vector<T> data_;

};












//////////////////////











using namespace std;
//using namespace bsp;
namespace bl = boost::lambda;








void inline test_MA(int const &N,
           std::vector<int> & U,boost::multi_array<int, 2>& AM,vector<int> &V)
           {


int i,j;


    for( i=0;i<N;i++)
     {

       for( j=0;j<N;j++)
        {
          V[i]+= AM[i][j]*U[j];

          }
     }
}

void inline test_madata(int const &N,
           std::vector<int> & U,data<int>&M,vector<int> &V)
           {


int i,j;


    for( i=0;i<N;i++)
     {

       for( j=0;j<N;j++)
        {
          V[i]+= M(i,j)*U[j];

          }
     }
}


// implanter les collectives MPI en BSP++
void test_BF_seq(int argc, char** argv)
{
int N;
double t1,t2;
    N=atoi(argv[1]);


    vector<int> A(N);
    vector<int> B(N);


data<int> M(N,N);


    typedef boost::multi_array<int, 2> array_type;
    typedef array_type::index index;
    array_type AM(boost::extents[N][N]);



for(int i=0;i<N;i++){
    for(int j=0;j<N;j++)
      {
       M(i,j)=1;
       }
  }



 for(index ii=0;ii<N;ii++){
    for(index jj=0;jj<N;jj++)
      {
       AM[ii][jj]=1;
       }
  }
  for(int j=0;j<N;j++)
      {
       A[j]=0;
       B[j]=1;
       }



t1=get_time();
//for(int k=0;k<100;k++) test_MA(N,B,AM,A);
for(int k=0;k<100;k++) test_madata(N,B,M,A);


 t2=get_time();
cout<<" temps *  =  "<<(t2-t1)/100<<endl;

cout << A[0] << "\n";


}





/// bsp staff ////



////////////////////////////////////////////////////////////////////////////////
#if defined(__GNUC__)
#define BSP_PRAGMA(x) _Pragma (#x)
#elif defined(BOOST_MSVC)
#define BSP_PRAGMA(x) __pragma (#x)
#endif

////////////////////////////////////////////////////////////////////////////////
// Remove warning for enable_if on constructor and other generic functions.
////////////////////////////////////////////////////////////////////////////////
namespace bsp
{
  template<class T> void ignore_unused_param(T const&) {}
}






///////////*******************////////////

#include <omp.h>
//#include <boost/program_options.hpp>


namespace bsp
{
  namespace details
  {
   // namespace po = boost::program_options;

    ////////////////////////////////////////////////////////////////////////////
    // OpenMP runtime
    ////////////////////////////////////////////////////////////////////////////
    struct runtime
    {
      static void startup(int argc, char** argv)
      {/*
        po::options_description desc;
        desc.add_options()( "threads", po::value<int>());

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if(vm.count("threads")) omp_set_num_threads(vm["threads"].as<int>());
        */
      }

      static void shutdown() {}

      static int pid()      { return omp_get_thread_num();  }
      static int size()     { return omp_get_num_threads(); }

    };
  }
}

////////////////////////////////////////////////////////////////////////////////
// BSP Environnement helper macros
////////////////////////////////////////////////////////////////////////////////
#define BSP_STARTUP() BSP_PRAGMA( omp parallel )

/////////////***********************








//////********************//////////
namespace bsp
{
  namespace details
  {
    struct environment
    {
       environment(int argc,char** argv)  { runtime::startup(argc,argv);  }
      ~environment()                      { runtime::shutdown();          }
    };
  }
}
////////////******************///////




//////////////********///////////
#include <cstdio>


////////////////////////////////////////////////////////////////////////////////
// BSP Environnement start-up.
// Runtime calls to start a new BSP.
////////////////////////////////////////////////////////////////////////////////
#define BSP_FUNCTION(argc,argv)                                     \
bsp::details::environment BOOST_PP_CAT(env,__COUNTER__)(argc,argv); \
if (bool stop_ = false) {} else                                     \
for(; !stop_; stop_ = true)                                         \
 BSP_STARTUP()                                                      \

namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP machine PID
  // Returns the local PID on a BSP machine processor
  //////////////////////////////////////////////////////////////////////////////
  int inline pid() { return details::runtime::pid(); }

}

//////////**************///////////////


/////////************ par Stuff ******////


//#include <bsppp/core/environment.hpp>

namespace bsp
{
  namespace constant
  {
    class pid_
    {
      public:
      typedef int value_type;
      typedef int reference;
      typedef int const_reference;

      int operator*() const { return pid(); }
    };
  }

  //////////////////////////////////////////////////////////////////////////////
  // BSP pid_ parallel vector
  // pid_ is a predefined parallel vector so that *pid_ is always equal to local
  // parallel machine rank.
  //////////////////////////////////////////////////////////////////////////////
  constant::pid_ const pid_ = {};
}


///////////////////////
#include <boost/type_traits/remove_cv.hpp>
#include <boost/type_traits/integral_constant.hpp>
//#include <bsppp/core/pid.hpp>

namespace bsp
{
  template<class T> class par;

  namespace details
  {
    using boost::integral_constant;
    template<class T> struct is_par_impl                  : integral_constant<bool,false> {};
    template<class T> struct is_par_impl<par<T> >         : integral_constant<bool,true> {};
    template<>        struct is_par_impl<constant::pid_>  : integral_constant<bool,true> {};
  }

  namespace traits
  {
    ////////////////////////////////////////////////////////////////////////////
    // Does T behaves as a BSP Parallel vector
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct is_par : details::is_par_impl< typename boost::remove_cv<T>::type >
    {};
  }
}


///////////////////////////////////


#include <boost/mpl/or.hpp>
#include <boost/mpl/and.hpp>
#include <boost/type_traits/is_function.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/remove_pointer.hpp>

namespace bsp
{
  namespace details
  {
    template<class T>
    struct is_function_type
         : boost::mpl::or_< boost::is_function<T>
                          , boost::mpl::and_< boost::is_function<typename boost::remove_pointer<T>::type>
                                            , boost::is_pointer<T>
                                            >
                          > {};
  }
}

//////////////////////////////////////
namespace bsp
{
  namespace details
  {
    ////////////////////////////////////////////////////////////////////////////
    /// SFINAE check on type existence
    /// If type T is a valid type, then enable_if<T,R>::type evaluates to R
    ////////////////////////////////////////////////////////////////////////////
    template<class T, class Result=void> struct enable_if_type
    {
      typedef Result type;
    };
  }
}


/////////////////
#include <boost/mpl/or.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/function_types/result_type.hpp>
//#include <bsppp/details/traits/enable_if_type.hpp>

namespace bsp
{
  namespace details
  {
    //////////////////////////////////////////////////////////////////////////
    // Is result_type defined in a given type ?
    //////////////////////////////////////////////////////////////////////////
    BOOST_MPL_HAS_XXX_TRAIT_DEF(result_type)

    //////////////////////////////////////////////////////////////////////////
    // Is a inner result struct defined in a given type ?
    //////////////////////////////////////////////////////////////////////////
    template<class F, class FArgs, class Enable=void>
    struct result_defined
         : boost::false_type {};

    template<class F, class Args>
    struct result_defined< F
                         , Args
                         , typename enable_if_type<
                                    typename F::template result<Args>::type
                                                        >::type
                         >
         : boost::true_type {};

    namespace bft = boost::function_types;

    ////////////////////////////////////////////////////////////////////////////
    /// Checks for result_of protocol compliance
    /// Return boost::true_type if boost::result_of<T>::type is defined.
    ////////////////////////////////////////////////////////////////////////////
    template<class T, class Enable=void>
    struct is_result_of_supported : boost::false_type {};

    template<class T>
    struct is_result_of_supported<T, typename boost::enable_if<
          boost::mpl::or_< has_result_type<typename bft::result_type<T>::type>
                         , result_defined<typename bft::result_type<T>::type,T>
                         >
            >::type
        > : boost::true_type {};
  }
}



//////////////////////////
#include <boost/lambda/lambda.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/equal.hpp>
//#include <bsppp/details/traits/is_function_type.hpp>
//#include <bsppp/details/traits/is_result_of_supported.hpp>
#include <boost/type_traits/is_void.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/function_types/function_arity.hpp>
#include <boost/function_types/parameter_types.hpp>
#include <boost/function_types/result_type.hpp>

namespace bsp
{
  namespace details
  {
    namespace bm = boost::mpl;
    namespace bf = boost::function_types;

    ////////////////////////////////////////////////////////////////////////////
    // Types are BSP compatible if :
    // - they're a PFO that support a T(int) call
    // - they're an unary function which :
    //        - as only one arguments
    //        - this one argument is integral
    //        - returns non-void type
    ////////////////////////////////////////////////////////////////////////////
    template<class T, bool EnableIf = details::is_function_type<T>::value>
    struct is_bsp_callable_impl
         : details::is_result_of_supported<T(int)>
    {};

    template<class T>
    struct is_bsp_callable_impl<T,true>
         : bm::and_< bm::bool_< bf::function_arity<T>::value == 1 >
                   , boost::is_integral<typename bm::at_c<typename bf::parameter_types<T>::type
                                                         ,0
                                                         >::type
                                       >
                   , bm::not_< boost::is_void<typename bf::result_type<T>::type> >
                   >
    {};
   }

  namespace traits
  {
    ////////////////////////////////////////////////////////////////////////////
    // Check if T can be used as a BSP compatible function
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct is_bsp_callable : details::is_bsp_callable_impl<T> {};

    ////////////////////////////////////////////////////////////////////////////
    // Overload for boost::lambda
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct is_bsp_callable<boost::lambda::lambda_functor<T> > : boost::true_type {};
  }
}







//////////////////////////////
#include <boost/function.hpp>
#include <boost/mpl/assert.hpp>
//#include <bsppp/details/macros.hpp>
//#include <bsppp/core/environment.hpp>
#include <boost/utility/enable_if.hpp>
//#include <bsppp/core/traits/is_par.hpp>
#include <boost/type_traits/is_convertible.hpp>
//#include <bsppp/core/traits/is_bsp_callable.hpp>

namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP Parallel vector
  // Parallels vector are the main data-structure used by BSP programs
  //////////////////////////////////////////////////////////////////////////////
  template<class T> class par
  {
    ////////////////////////////////////////////////////////////////////////////
    // Compile-time prevention of nested parallelism
    ////////////////////////////////////////////////////////////////////////////
    BOOST_MPL_ASSERT_MSG( (boost::mpl::not_< traits::is_par<T> >::value)
                        , BSP_NO_SUPPORT_FOR_NESTED_PARALLELISM
                        , (par<T>)
                        );

    public:
    ////////////////////////////////////////////////////////////////////////////
    // public typedefs for value and operator* return types
    ////////////////////////////////////////////////////////////////////////////
    typedef T         value_type;
    typedef T*        pointer;
    typedef T const*  const_pointer;
    typedef T&        reference;
    typedef T const&  const_reference;

    ////////////////////////////////////////////////////////////////////////////
    // Defautl Ctor
    ////////////////////////////////////////////////////////////////////////////
    par() : data_() {}

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a value_type. Sematically equivalent to replicate
    ////////////////////////////////////////////////////////////////////////////
    par( const_reference v )  : data_(v)  {  }

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a par<U>
    ////////////////////////////////////////////////////////////////////////////
    template<class U>
    par( par<U> const& v
       , typename boost::enable_if< boost::is_convertible<T,U> >::type* = 0
       )
    : data_(*v) {}

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a BSP Callable Entity
    ////////////////////////////////////////////////////////////////////////////
    template<class F>
    par( F f
       , typename boost::enable_if< traits::is_bsp_callable<F> >::type* = 0
       )
    : data_(f) {}

    ////////////////////////////////////////////////////////////////////////////
    // Ctor from a C-Array. tab[i] is owned by processor with pid==i.
    ////////////////////////////////////////////////////////////////////////////
    template<int N>   par( const T (& t)[N] ) : data_(t[pid()]) {}

    ////////////////////////////////////////////////////////////////////////////
    // Affectation from value_type
    ////////////////////////////////////////////////////////////////////////////
    par& operator=( const_reference v )
    {
      data_ = v;
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Affectation from a par<U>
    ////////////////////////////////////////////////////////////////////////////
    template<class U>
    typename boost::enable_if< boost::is_convertible<T,U>, par&>::type
    operator=( par<U> const& v )
    {
      data_ = *v;
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    // Affectation from a BSP Callable Entity
    ////////////////////////////////////////////////////////////////////////////
    template<class F>
    typename boost::enable_if< traits::is_bsp_callable<F>, par&>::type
    operator=( F f )
    {
      data_ = f;
      return *this;
    }
    ////////////////////////////////////////////////////////////////////////////
    // Affectation from a C-Array. tab[i] is owned by processor with pid==i.
    ////////////////////////////////////////////////////////////////////////////
    template<int N>   par& operator=( const T (& t)[N] )
    {
      data_ = t[pid()];
      return *this;
    }

    ////////////////////////////////////////////////////////////////////////////
    // operator* is the equivalent to $.$ in BSML v2
    // e.g. : let u = $v$; <-> u = *v;
    ////////////////////////////////////////////////////////////////////////////
    reference       operator*()       { return data_;  }
    const_reference operator*() const { return data_;  }

    ////////////////////////////////////////////////////////////////////////////
    // operator-> is the equivalent to $.$ in BSML v2 for method calls
    ////////////////////////////////////////////////////////////////////////////
    pointer       operator->()       { return data_;  }
    const_pointer operator->() const { return data_;  }

    private:
    ////////////////////////////////////////////////////////////////////////////
    // par<T> holds one value_type per machine in the BSP environment.
    ////////////////////////////////////////////////////////////////////////////
    value_type data_;
  };
}




/////////////////////////////////////////
/////////////////// sync staff /////////////
namespace bsp
{
  void inline synchronize()
  {
    #pragma omp barrier
  }
}

///////////////////////////////////////

//////////////  put staff ///////////



namespace bsp
{
  namespace details
  {
    ////////////////////////////////////////////////////////////////////////////
    // OpenMP BSP Machine memory allocation
    ////////////////////////////////////////////////////////////////////////////
    template<class T> inline void alloc(T*& data,int size)
    {
      static T* tmp;

      #pragma omp single
      tmp =  new T[size];

      data = tmp;
    }

    ////////////////////////////////////////////////////////////////////////////
    // OpenMP BSP Machine memory desallocation
    ////////////////////////////////////////////////////////////////////////////
    template<class T> inline void release(T*& data)
    {
      #pragma omp single
      if(!data) delete[] data;

      data = 0;
    }
  }
}



///////////////////////////////
#include <algorithm>
//#include <bsppp/details/environment.hpp>
//#include <bsppp/details/memory.hpp>

////////////////////////////////////////////////////////////////////////////////
/// buffer<T> is a fixed-size, dynamic array with a swallow copy semantic
////////////////////////////////////////////////////////////////////////////////
namespace bsp
{
  namespace details
  {
    template<class T> class buffer
    {
      public:
      typedef T           value_type;
      typedef T&          reference;
      typedef T const &   const_reference;

      buffer(size_t size) : size_(size) { details::alloc(data_,size_);  }
      buffer& operator=( buffer src )   { swap(src); return *this;  } // no throws

      ~buffer() { release(data_); }

      void swap( buffer& dst ) // no throws
      {
        std::swap(size_,dst.size_);
        std::swap(data_,dst.data_);
      }

      reference       operator[](size_t i)        { return data_[i];  }
      const_reference operator[](size_t i)  const { return data_[i];  }

      private:
      size_t  size_;
      T*      data_;
    };

    ////////////////////////////////////////////////////////////////////////////
    // swap function
    ////////////////////////////////////////////////////////////////////////////
    template<class T> inline
    void swap( buffer<T>& a, buffer<T>& b ) { a.swap(b); }
  }
}



///////////////////////
#include <boost/lambda/lambda.hpp>
#include <boost/utility/result_of.hpp>
//#include <boost/function_types/result_type.hpp>
//#include <bsppp/details/traits/is_function_type.hpp>

namespace bsp
{
  namespace details
  {
    namespace bm = boost::mpl;
    namespace bf = boost::function_types;

    ////////////////////////////////////////////////////////////////////////////
    // BSP Callable entity returns type either
    // - as a real function
    // - as a PFO
    ////////////////////////////////////////////////////////////////////////////
    template<class T, bool EnableIf = details::is_function_type<T>::value>
    struct bsp_result_impl : boost::result_of<T(int)> {};

    template<class T>
    struct bsp_result_impl<T,true> : bf::result_type<T> {};
   }

  namespace traits
  {
    ////////////////////////////////////////////////////////////////////////////
    // Return the result type of a call to a BSP Callable Entity
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct bsp_result : details::bsp_result_impl<T> {};

    ////////////////////////////////////////////////////////////////////////////
    // Overload for boost::lambda
    ////////////////////////////////////////////////////////////////////////////
    template<class T>
    struct bsp_result<boost::lambda::lambda_functor<T> >
    {
      typedef typename T::template sig< boost::tuple<int> >::type type;
    };
  }
}




/////////////////////////////////
//#include <bsppp/details/memory/buffer.hpp>

namespace bsp
{
  namespace details
  {
    template<class T> struct put_impl
    {
      static inline int extent()   { return bsp::details::runtime::size()*bsp::details::runtime::size(); }

      static inline void init(buffer<T>& data,boost::function<T(int)> const& f,int const& pid1,int const& size1)
      {

        int offset = pid1*size1;
        for(int i=0;i<size1;++i) data[i+offset] = f(i);
        synchronize();
      }

      static inline T const& at(buffer<T> const& data,int i,int const& pid1,int const& size1) { return data[i*size1+pid1]; }
    };
  }
}





///////////////////////////////////////////
#include <boost/function.hpp>
//#include <bsppp/details/memory/buffer.hpp>
//#include <bsppp/core/traits/bsp_result.hpp>
//#include <bsppp/details/primitives/put/omp.hpp>

namespace bsp
{
  namespace details
  {
    template<class Func> struct put_data
    {
      typedef typename traits::bsp_result<Func>::type base;

      put_data(): pid1(pid()), size1(bsp::details::runtime::size()) {}

      put_data(par< Func > const& f) : function_(*f), pid1(pid()),size1(bsp::details::runtime::size()) {}

      void reset(put_data const& v,buffer<base>* p)
      {
        function_ = v.function_;
        data_     = p;
        put_impl<base>::init(*data_,function_,pid1,size1);
      }

      typedef base const& result_type;
      result_type operator()(int i) const
      {
        return put_impl<base>::at(*data_,i,pid1,size1);
      }

      private:
      Func        function_;
      buffer<base>*  data_;

      int pid1;
      int size1;
    };
  }
}




////////////////////////////////////////
#include <boost/function.hpp>
//#include <bsppp/details/memory/buffer.hpp>
//#include <bsppp/details/primitives/put/data.hpp>






namespace bsp
{
  //////////////////////////////////////////////////////////////////////////////
  // BSP Parallel vector of put() result.
  // This one is optimized so it doesn't allocate too much memory for the put
  // result arrays. This is hidden by the result_of::put<T> type.
  //////////////////////////////////////////////////////////////////////////////
  template<class T> class par< details::put_data<T> >
  {
    public:
    typedef details::put_data<T>        value_type;
    typedef details::put_data<T>&       reference;
    typedef details::put_data<T> const& const_reference;
    typedef typename value_type::base   base;

    par() : results_(details::put_impl<base>::extent()) {}

    par( const_reference f ) : results_(details::put_impl<base>::extent())
    {
      data_.reset(f,&results_);
    }

    par& operator=( const_reference f )
    {
      data_.reset(f,&results_);
      return *this;
    }

    reference       operator*()       { return data_;  }
    const_reference operator*() const { return data_;  }

    private:
    details::buffer<base> results_;
    value_type            data_;
  };



//  template<class T> inline
//  boost::iterator_range< typename std::vector<T>::iterator > split (std::vector<T> & value)
//   {
//
////     if (is_integral<T>::type == true_type)
////     {
////         return value;
////      }
////      else
////      {
//        int offset= value.size()/bsp::size();
//
//
//
//        return boost::make_iterator_range(value.begin()+(offset*bsp::pid()),value.begin()+(offset*bsp::pid())+offset);
//     // }
//
//      }



}



/////////////////////////////////
#include <boost/function.hpp>
//#include <bsppp/details/memory/buffer.hpp>
//#include <bsppp/details/primitives/put/par.hpp>
//#include <bsppp/core/traits/is_bsp_callable.hpp>

namespace bsp
{
  namespace result_of
  {
    template<class T> struct put { typedef par< details::put_data<T> > type; };
  }

  //////////////////////////////////////////////////////////////////////////////
  // PUT primitive
  //////////////////////////////////////////////////////////////////////////////
  template<class Func> inline
  typename boost::enable_if< traits::is_bsp_callable<Func>
                           , details::put_data<Func>
                           >::type
   put(par< Func > const& f)
  {
    return details::put_data<Func>(f);
  }
}




////////////////////////////////////

vector<int>const & sender2( int to, bsp::par<vector<int> > const& p,int a, int b )
{

  return  *p;
}



void test_BF_BSP(int argc, char** argv)
{
    BSP_FUNCTION(argc,argv)
  {

    double t1,t2;


    int N,P=bsp::details::runtime::size();
    N=atoi(argv[1]);

    bsp::par<vector<int> > p;
    p=vector<int> (20);

    vector<int> A(N/P);
    vector<int> B(N/P);


    data<int> M(N/P,N/P);


//    typedef boost::multi_array<int, 2> array_type;
//    typedef array_type::index index;
//    array_type AM(boost::extents[N/P][N/P]);
//
//
//
// for(index ii=0;ii<N/P;ii++){
//    for(index jj=0;jj<N/P;jj++)
//      {
//       AM[ii][jj]=1;
//       }
//  }



 for(int i=0;i<N/P;i++){
    for(int j=0;j<N/P;j++)
      {
       M(i,j)=1;
       }
  }
  for(int j=0;j<N/P;j++)
      {
       A[j]=0;
       B[j]=1;
       }


  for(int i=0;i<20;i++)
      (*p)[i]=0;


   bsp::par< boost::function<vector<int>(int)> > s = bl::bind(sender2,bl::_1,p,2,3);
    bsp::result_of::put< boost::function<vector<int>(int)> >::type recv;

    recv = put( s );




t1=get_time();
for(int k=0;k<100;k++) test_madata(N/P,B,M,A);


 t2=get_time();
cout<<" temps *  =  "<<(t2-t1)/100<<endl;

cout << A[0] << "\n";








}

}




int main(int argc, char** argv)
{
  //test_BF_seq(argc,argv);
  test_BF_BSP(argc,argv);

  return 0;
}

