//
//  main.cpp
//  SingleSiteMST
//
//  Created by Xianglin Liu on 11/27/18.
//  Copyright © 2018 Xianglin Liu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <complex>
#include "Lambda_indices.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using namespace Lambda_indices;

void print_index(const vector<int> &kapdex, int lmax)
{
	int k, l, m;
	cout << std::setw(3) << kapdex[0];
	cout << std::setw(3) << kapdex[1];
	cout << endl;
	k=2;
	for (l = 1; l<=lmax; l++)
	{
		for (m = -2*l+1; m<=2*l-1; m+=2)
		{
			cout << std::setw(3) << kapdex[k];
			k+=1;
		}
		cout << endl;
		for (m = -2*l-1; m<=2*l+1; m+=2)
		{
			cout << std::setw(3) << kapdex[k];
			k+=1;
		}
		cout << endl;
	}
}

int main()
{
	cout << "***********************************************" << endl;
	cout << "     Test of the Lambda_indices class" << endl;
	Angular_index angular0;
	int lmax = angular0.get_lmax();
	
	cout << " kapdex=" << endl;
	print_index( angular0.get_kapdex(), lmax );
	
	cout << " ldex=" << endl;
	print_index( angular0.get_ldex(), lmax );
	
	cout << " jdex=" << endl;
	print_index( angular0.get_jdex(), lmax );
	
	cout << " mydex=" << endl;
	print_index( angular0.get_mydex(), lmax );
	
	cout << " ldex_bar=" << endl;
	print_index( angular0.get_ldex_bar(), lmax );
	
	return 0;
}
