
#include <iostream>
#include <bsppp/bsppp.hpp>



using namespace std;


namespace bl = boost::lambda;


int bsp_main(int argc, char** argv)
{

    par<int> a;
    a=pid()*3;

cout<<"I m process rank "<<pid()<<" of "<<size()<<"my local value of a is "<<*a<<endl;

    return 0;
}

