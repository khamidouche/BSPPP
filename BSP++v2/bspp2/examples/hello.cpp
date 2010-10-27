
#include <iostream>
#include <bsppp/bsppp.hpp>

#include <functional>
#include <numeric>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;


namespace bl = boost::lambda;
//
int sender2( int ind, par<int> const& v )
{
  return *v;
}

//#include <boost/range/adaptor/sliced.hpp>

//struct linear
//{
//  template<class Sig> struct result;
//  template<class This,class Value>
//  struct result<This(Value,std::size_t,std::size_t)>
//  {
//    typedef boost::iterator_range< typename boost::range_iterator<Value const>::type > type;
//  };
//
//  template<class Value> inline
//  typename result<linear(Value,std::size_t,std::size_t)>::type
//  operator()(Value const& v, std::size_t pid,std::size_t sz) const
//  {
//    std::size_t rs = boost::size(v)/sz;
//    return boost::adaptors::slice(v,pid*rs,(pid+1)*rs);
//  }
//};

int bsp_main(int argc, char** argv)
{
    //std::cout<<"pid = "<<pid()<<std::endl;
    par<vector<int> > a;
    a=vector<int> (20);

for(int i=0;i<20;i++)
     (*a)[i]=i;

//par< boost::function<int (int)> > s = bl::bind(sender2,bl::_1,a);
//    result_of_put< boost::function<int(int)> >::type recv;
//
//    recv = put( s );
//int sum=0;
//for(int i=0;i<size();i++) sum+=(*recv)(i);
//std::cout<<"*** pid== "<<pid()<<"  put  = "<<sum<<std::endl;


     BSP_HYB_START(argc,argv)
     {

       typedef result_of_split<vector<int>,linear>::type sliced_type;
       sliced_type b = split(*a,linear());

       result_of_proj<sliced_type::value_type>::type pb = proj(b);

       for(int i=0;i<size();i++)
         for(int j=0;j<boost::size(pb(i));j++)
        printf("pid %d = %d\n",pid(),(pb(i))[j]);

     }
     BSP_HYB_END()



    return 0;
}

//
//int sender0( int ind, par<int > const& v, int const& rank_ )
//{
//  if(rank_==0)  return *v;
//  else return int();
//}
//
//
//vector<int> sender1( int ind, par<vector<int> > const& v )
//{
//  if(ind==0)  return *v;
//  else return vector<int>();
//}
//vector<int> sender2( int ind, par<vector<int> > const& v, vector<int> const& pivot, int const& rank_ )
//{
//  if(rank_==0)  return pivot;
//  else return vector<int>();
//}
//
//vector<int> sender3( int ind, par<vector<int> > const& v, vector<par<vector<int> > > const& part )
//{
//
//   return (*part[ind]);
//}
//
//void select1(vector<int> & out, vector<int> const& in, int step)
//{
//    int i,j=0;
//    for(i=step;i<in.size();i+=step,j++)
//     {
//         out[j]=in[i];
//     }
//}
//void select2(vector<int> & out, vector<int> const& in, int nbproc)
//{
//    int i,j=0;
//    for(i=1;i<nbproc;i++,j++)
//     out[j]=in[i*nbproc+(nbproc/2)];
//}
//
//
//
//void fill_Gsampl(vector<int>& out, result_of_put< boost::function<vector<int> (int)> >::type const& recv, int nbproc )
//{
//    for(int i=0;i<nbproc;i++)
//    for(int j=0;j<nbproc;j++)
//    out[j+i*nbproc]=(*recv)(i)[j];
//}
//
//
//void create_part(vector<par<vector<int> > >& out,vector<int> const& in, result_of_put< boost::function<vector<int> (int)> >::type const& recv,int nbproc )
//{
//    int i,j,k;
//   k=0;
//
//
//        for(i=0;i<nbproc;i++)
//        {
//            j=0;
//            out[i]=vector<int> ();
//            //cout<<"inside ****   pid   "<<pid()<<"   i== "<<i <<endl;
//            while((in[k]<=(*recv)(0)[i])&&(k<in.size()))
//            {
//                (*out[i]).push_back(in[k]);
//
////                  cout<<" /////// pid = "<<pid()<<"  out["<<i<<"]["<<j<<"] = "<<(*out[i])[j]<<endl;
////                  cout<<" /*/*/*/ pid = "<<pid()<<"  in["<<k<<"]= "<<in[k]<<endl;
//                   k++;j++;
//            }
//        }
//        //k++;
//
//
//
//}
//void merge_out(vector<int> & out,result_of_put< boost::function<vector<int> (int)> >::type const& recv,int nbproc )
//{
//
//    for(int i=0;i<nbproc;i++)
//    for(int j=0;j<(*recv)(i).size();j++)
//    {
//        out.push_back((*recv)(i)[j]);
//
//    }
//}
//
//int RandomNumber () { return (rand()%100); }
//
//
//int bsp_main(int argc, char** argv)
//{
//
//
//    /// BSP PSRS ///
//
//
//    int rank_, nbproc,n;
//
//    rank_=pid();
//    nbproc= size();
//
//
//    srand ( unsigned ( time(NULL) )*rank_ );
//
//    /// communication of the data size ///
//
//    par<int> N;
//    if(rank_==0) *N=atoi(argv[1]);
//
//    par< boost::function<int (int)> > s0 = bl::bind(sender0,bl::_1,N, rank_);
//    result_of_put< boost::function<int (int)> >::type recv0;
//    recv0 = put( s0 );
//
//    n=(*recv0)(0);
//    /// ****************** ///
//
//    //cout<<"ok  "<<rank_<<"  "<<nbproc<<"   n= "<<n<<endl;
//
//    par<vector<int> > Gvect;
//    Gvect=vector<int> (n/nbproc);
//
//
//    par<vector<int> > Sampl;
//    Sampl=vector<int> (nbproc);
//
//    generate (Gvect->begin(), Gvect->end(), RandomNumber);
//
//    sort(Gvect->begin(), Gvect->end());
//
//    select1(*Sampl,*Gvect, n/(nbproc*nbproc));
//
//
//    par< boost::function<vector<int> (int)> > s1 = bl::bind(sender1,bl::_1,Sampl);
//    result_of_put< boost::function<vector<int> (int)> >::type recv1;
//    recv1 = put( s1 );
//
//    /// step 2 //////
//
//
//    vector<int> pivot;
//    if(rank_==0)
//    {
//        vector<int> Gsampl;
//        Gsampl=vector<int>(nbproc*nbproc);
//
//        pivot=vector<int>(nbproc-1);
//
//        fill_Gsampl(Gsampl, recv1, nbproc);
//
//
//        sort(Gsampl.begin(), Gsampl.end());
//
//
//        select2(pivot, Gsampl, nbproc);
//
//
//    }
//    par< boost::function<vector<int> (int)> > s2 = bl::bind(sender2,bl::_1,Sampl, pivot, rank_);
//    result_of_put< boost::function<vector<int> (int)> >::type recv2;
//    recv2 = put( s2 );
//
//    /// step 3 ////////
//
//    vector<par< vector<int> > > part;
//    part=vector<par< vector<int> > >(nbproc);
//
//    create_part(part,*Gvect,recv2,nbproc);
//
//
//    par< boost::function<vector<int> (int)> > s3 = bl::bind(sender3,bl::_1,Sampl, part);
//    result_of_put< boost::function<vector<int> (int)> >::type recv3;
//    recv3 = put( s3 );
//
//
//    /// step 4 ///
//
//    par<vector<int> >  output;
//    output= vector<int> ();
//
//    merge_out(*output,recv3,nbproc );
//
//    sort(output->begin(), output->end());
//
//    synchronize();
//
//
//    ////****  display the input and output  ****///////
//
//    for(int i=0;i<(*output).size();i++)
//    cout<<" pid = "<<rank_<<"  in["<<i<<"] = "<<(*Gvect)[i]<<" out["<<i<<"]=  "<<(*output)[i]<<endl;
//    synchronize();
//
//
//
//return 0;
//}


