//
//  Array3d.cpp
//
//
//  Created by Xianglin Liu on 12/26/18.
//
//	Test various declaration, initialization, and assignment of the Array3d classes.

#include "Array3d.hpp"
#include <complex>

using std::complex;
using namespace Array3d;

int main(int argc, const char * argv[])
{
	int col=3, row=2;
	Array2d<double> mat(col,row);
	mat = 0.0;
	print_test_Array2d<double>(mat);
	
	int dep=2;
	Array3d<double> mat3d(col,row,dep);
	mat3d = 0.0;
	print_test_Array3d<double>(mat3d);
	
	Array2d<double>* matpt;
	matpt = &mat;
	print_test_Array2d((*matpt));
	
	//	Array2d<double> new_mat = mat;
	//	Array2d<double> new_mat(mat);
	Array2d<double> new_mat;
	new_mat = mat;
	print_test_Array2d(new_mat);
	
	//	Array3d<double> new_mat3d = mat3d;
	Array3d<double> new_mat3d;
	new_mat3d = mat3d;
	print_test_Array3d(new_mat3d);
	
	complex<double> I(0.0,1.0);
	Array2d< complex<double> > matcomplex;
	matcomplex = I;
	cout << "i=" << I << endl;
	
}

