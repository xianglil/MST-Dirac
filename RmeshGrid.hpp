//
//  RmeshGrid.hpp
//  
//
//  Created by Xianglin Liu on 12/26/18.
//
//

#ifndef RmeshGrid_h
#define RmeshGrid_h

#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::endl;

namespace RmeshGrid
{
	class Rmesh0
	{
		public:
			//		default constructor
			Rmesh0(): nr(0), rstart(0), rend(0), dx(0), rmesh(nullptr)
			{;}
			
			//		direct constructor
			Rmesh0( int nr_in, double rstart_in, double rend_in ):
			nr(nr_in), rstart(rstart_in), rend(rend_in),
			dx( (log(rend_in)-log(rstart_in))/(nr_in-1) )
			{
				try
				{
					rmesh = new double [nr];
				}
				catch (std::bad_alloc&)
				{
					cout << "Error allocating memory !" << endl;
					cout << "At class " << classname() << endl;
					std::exit(EXIT_FAILURE);
					
				}
				
				for ( int i=0; i<nr; i++ )
				{
					rmesh[i] = rstart*exp(i*dx);
				}
			}
			
			//		copy constructor
			Rmesh0( const Rmesh0 &a ):
			nr(a.nr), rstart(a.rstart), rend(a.rend), dx(a.dx)
			{
				try
				{
					rmesh = new double [nr];
				}
				catch (std::bad_alloc&)
				{
					cout << "Error allocating memory !" << endl;
					cout << "At class " << classname() << endl;
					std::exit(EXIT_FAILURE);
				}
				for ( int i=0; i<nr; i++ )
				{
					rmesh[i] = a.rmesh[i];
				}
			}
			
			~Rmesh0()
			{
				delete [] rmesh;
				rmesh = nullptr;
			}
			
			//		overload operator = for copy assignment
			Rmesh0& operator=( const Rmesh0 &a )
			{
				if (this == &a) return *this;
				if (rmesh)
				{
					delete [] rmesh;
				}
				nr = a.nr;
				rstart = a.rstart;
				rend = a.rend;
				dx = a.rend;
				try
				{
					rmesh = new double [nr];
				}
				catch (std::bad_alloc&)
				{
					cout << "Error allocating memory !" << endl;
					cout << "At class " << classname() << endl;
					std::exit(EXIT_FAILURE);
				}
				for ( int i=0; i<nr; i++ )
				{
					rmesh[i] = a.rmesh[i];
				}
				return *this;
			}
			
			//		Methods to access the information of this class
			int get_nr() const { return nr; }
			double get_rstart() const { return rstart; }
			double get_rend() const { return rend; }
			double get_dx() const { return dx; }
			double* get_rmesh() const { return rmesh; }
			
		private:
			int nr;
			double rstart;
			double rend;
			double dx;
			double* rmesh;
			const char* classname() { return "Rmesh0"; }
	};

	void print_test_Rmesh()
	{
		int nr_in = 10;
		double rstart_in = 0.00001;
		double rend_in = 1.0000;
		Rmesh0 rmesh_in( nr_in, rstart_in, rend_in );
		Rmesh0 rmesh1 = rmesh_in;
		int nr=rmesh1.get_nr();
		double rstart = rmesh1.get_rstart();
		double rend = rmesh1.get_rend();
		double dx = rmesh1.get_dx();
		double* rmesh = rmesh1.get_rmesh();
		cout << "***********************************************" << endl;
		cout << "     Test of the Array3d class" << endl;
		cout << "nr=" << nr << endl;
		cout << "rstart=" << rstart << endl;
		cout << "rend=" << rend << endl;
		cout << "dx=" << dx << endl;
		for ( int i=0; i<nr; i++ )
			printf( "r_list[%d]=%.15f \n", i, rmesh[i] );
		cout << "Success run !\n";
		cout << "***********************************************" << endl;
	}
}
#endif /* RmeshGrid_h */
