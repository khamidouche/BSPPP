
#include <iostream>
#include <bsppp/bsppp.hpp>


#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;


namespace bl = boost::lambda;








int sender0( int ind, par<int > const& v, int const& rank_ )
{
  if(rank_==0)  return *v;
  else return int();
}


vector<int> sender1( int ind, par<vector<int> > const& v )
{
  if(ind==0)  return *v;
  else return vector<int>();
}
vector<int> sender2( int ind, par<vector<int> > const& v, vector<int> const& pivot, int const& rank_ )
{
  if(rank_==0)  return pivot;
  else return vector<int>();
}

vector<int> sender3( int ind, MPI::bsp::par<vector<int> > const& v, vector<MPI::bsp::par<vector<int> > > const& part )
{

   return (*part[ind]);
}
vector<int> sender3o( int ind, OMP::bsp::par<vector<int> > const& v, vector<OMP::bsp::par<vector<int> > > const& part )
{

   return (*part[ind]);
}

void select1(vector<int> & out, vector<int> const& in, int step)
{
    int i,j=0;
    for(i=step;i<in.size();i+=step,j++)
     {
         out[j]=in[i];
     }
}
void select2(vector<int> & out, vector<int> const& in, int nbproc)
{
    int i,j=0;
    for(i=1;i<nbproc;i++,j++)
     out[j]=in[i*nbproc+(nbproc/2)];
}



void fill_Gsampl(vector<int>& out, result_of_put< boost::function<vector<int> (int)> >::type const& recv, int nbproc )
{
    for(int i=0;i<nbproc;i++)
    for(int j=0;j<nbproc;j++)
    out[j+i*nbproc]=(*recv)(i)[j];
}


void fill_Gsampl_omp(vector<int>& out, OMP::bsp::result_of_put< boost::function<vector<int> (int)> >::type const& recv, int nbproc )
{
    for(int i=0;i<nbproc;i++)
    for(int j=0;j<nbproc;j++)
    out[j+i*nbproc]=(*recv)(i)[j];
}



void create_part(vector<par<vector<int> > >& out,vector<int> const& in, result_of_put< boost::function<vector<int> (int)> >::type const& recv,int nbproc )
{
    int i,j,k;
   k=0;


        for(i=0;i<nbproc;i++)
        {
            j=0;
            out[i]=vector<int> ();
            while((in[k]<=(*recv)(0)[i])&&(k<in.size()))
            {
                (*out[i]).push_back(in[k]);
                   k++;j++;
            }
        }




}


void create_part_omp(vector<OMP::bsp::par<vector<int> > >& out,vector<int> const& in, OMP::bsp::result_of_put< boost::function<vector<int> (int)> >::type const& recv,int nbproc )
{
    int i,j,k;
   k=0;


        for(i=0;i<nbproc;i++)
        {
            j=0;
            out[i]=vector<int> ();
            while((in[k]<=(*recv)(0)[i])&&(k<in.size()))
            {
                (*out[i]).push_back(in[k]);
                   k++;j++;
            }
        }




}

void merge_out(vector<int> & out,result_of_put< boost::function<vector<int> (int)> >::type const& recv,int nbproc )
{

    for(int i=0;i<nbproc;i++)
    for(int j=0;j<(*recv)(i).size();j++)
    {
        out.push_back((*recv)(i)[j]);
       // std::cout<<"** "<<(*recv)(i)[j]<<std::endl;

    }
}

void merge_out_omp(vector<int> & out,OMP::bsp::result_of_put< boost::function<vector<int> (int)> >::type const& recv,int nbproc )
{

    for(int i=0;i<nbproc;i++)
    for(int j=0;j<(*recv)(i).size();j++)
    {
        out.push_back((*recv)(i)[j]);

    }
}


int RandomNumber () { unsigned int seed; return (rand_r(&seed)%100); }

void SORT_HYB(int argc, char** argv,std::vector<int>& in, int n, std::vector<int>& out)
{

    BSP_HYB_START(argc, argv)
    {
         int rank_hyb, nbproc_hyb;

        rank_hyb=pid();
        nbproc_hyb= size();

//        typedef result_of_split<vector<int>,linear>::type sliced_type;
//         sliced_type Gvect_hyb = split(in,linear());

         par<vector<int> > Gvect_hyb;
        Gvect_hyb=vector<int> (n/nbproc_hyb);

        generate (Gvect_hyb->begin(), Gvect_hyb->end(), RandomNumber);

        //std::memcpy(*vect_cop,*Gvect_hyb,n/nbproc_hyb);

        //(*Gvect_hyb)[0]=2;
        par<vector<int> > Sampl_hyb;
        Sampl_hyb=vector<int> (nbproc_hyb);

        sort(Gvect_hyb->begin(), Gvect_hyb->end());


         //std::cout<<"rank = "<<rank_hyb<<" val = "<<(*Gvect_hyb)[3]<<std::endl;

        select1(*Sampl_hyb,*Gvect_hyb, n/(nbproc_hyb*nbproc_hyb));

        //synchronize();

        par< boost::function<vector<int> (int)> > s1_hyb = bl::bind(sender1,bl::_1,Sampl_hyb);
        result_of_put< boost::function<vector<int> (int)> >::type recv1_hyb;
        recv1_hyb = put( s1_hyb );

        /// step 2 //////


        vector<int> pivot_hyb;
        if(rank_hyb==0)
        {
            vector<int> Gsampl_hyb;
            Gsampl_hyb=vector<int>(nbproc_hyb*nbproc_hyb);

            pivot_hyb=vector<int>(nbproc_hyb-1);

            fill_Gsampl_omp(Gsampl_hyb, recv1_hyb, nbproc_hyb);


            sort(Gsampl_hyb.begin(), Gsampl_hyb.end());


            select2(pivot_hyb, Gsampl_hyb, nbproc_hyb);


        }
       // synchronize();

        par< boost::function<vector<int> (int)> > s2_hyb = bl::bind(sender2,bl::_1,Sampl_hyb, pivot_hyb, rank_hyb);
        result_of_put< boost::function<vector<int> (int)> >::type recv2_hyb;
        recv2_hyb = put( s2_hyb );

       // std::cout<<"**** rank= "<<rank_hyb<<"  recv2 = "<<((*recv2_hyb)(0))[0]<<std::endl;

        /// step 3 ////////

        vector<par< vector<int> > > part_hyb;
        part_hyb=vector<par< vector<int> > >(nbproc_hyb);

        create_part_omp(part_hyb,*Gvect_hyb,recv2_hyb,nbproc_hyb);
        //synchronize();
        //create_part_omp(part_hyb,*vect_cop,recv2_hyb,nbproc_hyb);
       // std::cout<<"**** rank= "<<rank_hyb<<"  pzrt  = "<<(*part_hyb[0])[0]<<std::endl;

        par< boost::function<vector<int> (int)> > s3_hyb = bl::bind(sender3o,bl::_1,Sampl_hyb, part_hyb);
        result_of_put< boost::function<vector<int> (int)> >::type recv3_hyb;
        recv3_hyb = put( s3_hyb );


        //std::cout<<"**** rank= "<<rank_hyb<<"  recv3 = "<<(*recv3_hyb)(1)[0]<<std::endl;
        /// step 4 ///
        synchronize();
        par<vector<int> >  output_hyb;
        output_hyb= vector<int> ();
/// il faut un split_ref   et utiliser l'input comme sortie ///
/// *Gvect_hyb.clean(); merge_out(*Gvect_Hyb, , )


//       // Gvect_hyb->clean();
        merge_out_omp(*output_hyb,recv3_hyb,nbproc_hyb );
       // std::cout<<"rank = "<<rank_hyb<<" size "<<output_hyb->size()<<std::endl;
//
        sort(output_hyb->begin(), output_hyb->end());
//
//        //std::cout<<"rank = "<<rank_hyb<<" val = "<<(*output_hyb)[3]<<std::endl;
//        synchronize();
//
//       // std::cout<<"rank = "<<rank_hyb<<" val = "<<(*output_hyb)[3]<<std::endl;
//

//        int offset=(n/nbproc_hyb)*rank_hyb;
//        std::memcpy(&(out[offset]),&(*output_hyb),n/nbproc_hyb);
//        synchronize();

       //std::cout<<"rank = "<<rank_hyb<<" val output  = "<<out[3+offset]<<std::endl;


    }
    BSP_HYB_END()
}


void SORT_HYB_2(int argc, char** argv,std::vector<int>& in, int n, std::vector<int>& out)
{

    BSP_HYB_START(argc, argv)
    {
         int rank_hyb, nbproc_hyb;

        rank_hyb=pid();
        nbproc_hyb= size();

//        typedef result_of_split<vector<int>,linear>::type sliced_type;
//         sliced_type Gvect_hyb = split(in,linear());

         par<vector<int> > Gvect_hyb;
         Gvect_hyb=vector<int> (n/nbproc_hyb);

         int offset=(n/nbproc_hyb)*rank_hyb;

         //std::cout<<" in  "<<in.size()<<std::endl;
         std::copy(&(in[offset]), &(in[offset+(n/nbproc_hyb)]), &((*Gvect_hyb)[0]));


       // generate (Gvect_hyb->begin(), Gvect_hyb->end(), RandomNumber);

        //std::memcpy(*vect_cop,*Gvect_hyb,n/nbproc_hyb);

        //(*Gvect_hyb)[0]=2;
        par<vector<int> > Sampl_hyb;
        Sampl_hyb=vector<int> (nbproc_hyb);

        sort(Gvect_hyb->begin(), Gvect_hyb->end());


         //std::cout<<"rank = "<<rank_hyb<<" val = "<<(*Gvect_hyb)[3]<<std::endl;

        select1(*Sampl_hyb,(*Gvect_hyb), n/(nbproc_hyb*nbproc_hyb));

        //synchronize();

        par< boost::function<vector<int> (int)> > s1_hyb = bl::bind(sender1,bl::_1,Sampl_hyb);
        result_of_put< boost::function<vector<int> (int)> >::type recv1_hyb;
        recv1_hyb = put( s1_hyb );

        /// step 2 //////


        vector<int> pivot_hyb;
        if(rank_hyb==0)
        {
            vector<int> Gsampl_hyb;
            Gsampl_hyb=vector<int>(nbproc_hyb*nbproc_hyb);

            pivot_hyb=vector<int>(nbproc_hyb-1);

            fill_Gsampl_omp(Gsampl_hyb, recv1_hyb, nbproc_hyb);


            sort(Gsampl_hyb.begin(), Gsampl_hyb.end());


            select2(pivot_hyb, Gsampl_hyb, nbproc_hyb);


        }
       // synchronize();

        par< boost::function<vector<int> (int)> > s2_hyb = bl::bind(sender2,bl::_1,Sampl_hyb, pivot_hyb, rank_hyb);
        result_of_put< boost::function<vector<int> (int)> >::type recv2_hyb;
        recv2_hyb = put( s2_hyb );

       // std::cout<<"**** rank= "<<rank_hyb<<"  recv2 = "<<((*recv2_hyb)(0))[0]<<std::endl;

        /// step 3 ////////

        vector<par< vector<int> > > part_hyb;
        part_hyb=vector<par< vector<int> > >(nbproc_hyb);

        create_part_omp(part_hyb,*Gvect_hyb,recv2_hyb,nbproc_hyb);
        //synchronize();
        //create_part_omp(part_hyb,*vect_cop,recv2_hyb,nbproc_hyb);
       // std::cout<<"**** rank= "<<rank_hyb<<"  pzrt  = "<<(*part_hyb[0])[0]<<std::endl;

        par< boost::function<vector<int> (int)> > s3_hyb = bl::bind(sender3o,bl::_1,Sampl_hyb, part_hyb);
        result_of_put< boost::function<vector<int> (int)> >::type recv3_hyb;
        recv3_hyb = put( s3_hyb );


        //std::cout<<"**** rank= "<<rank_hyb<<"  recv3 = "<<(*recv3_hyb)(1)[0]<<std::endl;
        /// step 4 ///
        synchronize();
        par<vector<int> >  output_hyb;
        output_hyb= vector<int> ();
/// il faut un split_ref   et utiliser l'input comme sortie ///
/// *Gvect_hyb.clean(); merge_out(*Gvect_Hyb, , )


//       // Gvect_hyb->clean();
        merge_out_omp(*output_hyb,recv3_hyb,nbproc_hyb );
       // std::cout<<"rank = "<<rank_hyb<<" size "<<output_hyb->size()<<std::endl;
//
        sort(output_hyb->begin(), output_hyb->end());
//
//        //std::cout<<"rank = "<<rank_hyb<<" val = "<<(*output_hyb)[3]<<std::endl;
//        synchronize();
//
//       // std::cout<<"rank = "<<rank_hyb<<" val = "<<(*output_hyb)[3]<<std::endl;
//

//        int offset=(n/nbproc_hyb)*rank_hyb;
//        std::memcpy(&(out[offset]),&(*output_hyb),n/nbproc_hyb);
//        synchronize();

       //std::cout<<"rank = "<<rank_hyb<<" val output  = "<<out[3+offset]<<std::endl;


    }
    BSP_HYB_END()
}






int bsp_main(int argc, char** argv)
{


    /// BSP PSRS ///


    int rank_, nbproc,n;
    double T1,T2,Tcomp,Tcomm;

    rank_=pid();
    nbproc= size();


    srand ( unsigned ( time(NULL) )*rank_ );

    /// communication of the data size ///

    par<int> N;
    if(rank_==0) *N=atoi(argv[1]);

    par< boost::function<int (int)> > s0 = bl::bind(sender0,bl::_1,N, rank_);
    result_of_put< boost::function<int (int)> >::type recv0;
    recv0 = put( s0 );

    n=(*recv0)(0);
    /// ****************** ///

    //cout<<"ok  "<<rank_<<"  "<<nbproc<<"   n= "<<n<<endl;

    par<vector<int> > Gvect;
    Gvect=vector<int> (n/nbproc);


    par<vector<int> > Sampl;
    Sampl=vector<int> (nbproc);

     generate (Gvect->begin(), Gvect->end(), RandomNumber);

    //sort(Gvect->begin(), Gvect->end());

    T1=time();
     SORT_HYB(argc, argv, *Gvect,Gvect->size(),*Gvect);
         // std::cout<<"la taille sortie "<<Gvect->size()<<std::endl;

    select1(*Sampl,*Gvect, n/(nbproc*nbproc));
    T2=time();
    Tcomp+=T2-T1;

    T1=time();
    par< boost::function<vector<int> (int)> > s1 = bl::bind(sender1,bl::_1,Sampl);
    result_of_put< boost::function<vector<int> (int)> >::type recv1;
    recv1 = put( s1 );
    T2=time();
    Tcomm+=T2-T1;

    /// step 2 //////


    vector<int> pivot;
    T1=time();
    if(rank_==0)
    {
        vector<int> Gsampl;
        Gsampl=vector<int>(nbproc*nbproc);

        pivot=vector<int>(nbproc-1);

        fill_Gsampl(Gsampl, recv1, nbproc);


        sort(Gsampl.begin(), Gsampl.end());
          //SORT_HYB(argc, argv, )

        select2(pivot, Gsampl, nbproc);


    }
    T2=time();
    Tcomp+=T2-T1;

    T1=time();
    par< boost::function<vector<int> (int)> > s2 = bl::bind(sender2,bl::_1,Sampl, pivot, rank_);
    result_of_put< boost::function<vector<int> (int)> >::type recv2;
    recv2 = put( s2 );
    T2=time();
    Tcomm+=T2-T1;
    /// step 3 ////////

    vector<par< vector<int> > > part;
    part=vector<par< vector<int> > >(nbproc);
    T1=time();
    create_part(part,*Gvect,recv2,nbproc);
    T2=time();
    Tcomp+=T2-T1;


    T1=time();
    par< boost::function<vector<int> (int)> > s3 = bl::bind(sender3,bl::_1,Sampl, part);
    result_of_put< boost::function<vector<int> (int)> >::type recv3;
    recv3 = put( s3 );
    T2=time();
    Tcomm+=T2-T1;


     //std::cout<<"rank "<<rank_<<(*recv3)(0)[1]<<std::endl;
    /// step 4 ///

    par<vector<int> >  output;
    output= vector<int> ();
     par<vector<int> >  output1;
    output1= vector<int> (n/nbproc);


    T1=time();
    merge_out(*output,recv3,nbproc );

    //std::cout<<"rank "<<rank_<<output->size()<<std::endl;
    generate (output1->begin(), output1->end(), RandomNumber);

   // sort(output->begin(), output->end());
   SORT_HYB_2(argc,argv, *output1,output1->size(),*output1);
  // SORT_HYB(argc,argv, *output,output->size(),*output);
    T2=time();
    Tcomp+=T2-T1;
    synchronize();


    ////****  display the input and output  ****///////

//    for(int i=0;i<(*output).size();i++)
//    cout<<" pid = "<<rank_<<"  out["<<i<<"] = "<<(*output)[i]<<endl;
//    synchronize();

     if (rank_==0) cout<<"tcomp "<<Tcomp<<" Tcomm "<<Tcomm<<std::endl;



return 0;
}

