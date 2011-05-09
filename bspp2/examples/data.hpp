/******************************************************************************
 *         Copyright 2009      LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/

#ifndef  DATA_HPP__INCLUDED__
#define  DATA_HPP__INCLUDED__

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






#endif
