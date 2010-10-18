
#include <iostream>
#include <bsppp/bsppp.hpp>

using namespace std;
using namespace bsp;

int bsp_main(int argc, char** argv)
{
    std::cout <<"rank = "<<bsp::pid()<<std::endl;

return 0;
}

/*
#include <iostream>
#include <bsppp/bsppp.hpp>

using namespace std;
using namespace bsp;

namespace bl = boost::lambda;

int bsp_main(int argc, char** argv)
{
    std::cout<<"pid = "<<bsp::pid()<<std::endl;



    return 0;
}
*/
