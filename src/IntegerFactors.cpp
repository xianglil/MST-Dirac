//
//  IntegerFactors.cpp
//  
//
//  Created by Xianglin Liu on 1/1/19.
//
//

#include "IntegerFactors.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using IntegerFactors::Factors;

void print_kl(const vector<int> vec_kl, int lmax)
{
	int kl = 0;
	for (int l=0; l<=lmax; l++)
	{
		int n = (l+1)*(l+2)/2-l-1;
		for (int m=-l; m<=l; m++)
		{
			cout << std::setw(3) << vec_kl[kl];
			kl++;
		}
		cout << endl;
	}
	
}

void print_jl(const vector<int> vec_jl, int lmax)
{
	int jl = 0;
	for (int l=0; l<=lmax; l++)
	{
		for (int m=0; m<=l; m++)
		{
			cout << std::setw(3) << vec_jl[jl];
			jl++;
		}
		cout << endl;
	}
	
}

void print_test_Factors(const Factors &factor, int lmax)
{
	cout << "***********************************************" << endl;
	cout << "     Test of the Factors class" << endl;
	cout << "***********************************************" << endl;
	cout << "     lofk" << endl;
	print_kl(factor.lofk, lmax);
	cout << "     mofk" << endl;
	print_kl(factor.mofk, lmax);
	cout << "     jofk" << endl;
	print_kl(factor.jofk, lmax);
	cout << "     lofj" << endl;
	print_jl(factor.lofj, lmax);
	cout << "     mofj" << endl;
	print_jl(factor.mofj, lmax);
	cout << "     kofj" << endl;
	print_jl(factor.kofj, lmax);
	
}

int main()
{
	Factors factor;
	int lmax=factor.lmax;
	print_test_Factors(factor, lmax);
}

/*
vector<int> lofk(kmax);
vector<int> mofk(kmax);
vector<int> jofk(kmax);
vector<int> lofj(jmax);
vector<int> mofj(jmax);
vector<int> kofj(jmax);
*/