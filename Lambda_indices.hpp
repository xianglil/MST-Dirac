//
//  Lambda_indices.hpp
//  SingleSiteMST
//
//  Created by Xianglin Liu on 11/27/18.
//  Copyright © 2018 Xianglin Liu. All rights reserved.
//

#ifndef Lambda_indices_hpp
#define Lambda_indices_hpp

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

namespace Lambda_indices
{
	class Angular_index
	{
	public:
		
		Angular_index(int lmax_in = 6 ):
		lmax(lmax_in), kmax(2*(lmax_in+1)*(lmax_in+1))
		{
			assign_index();
			check_length();
		}
		
		const vector<int> &get_kapdex() const { return kapdex; }
		const vector<int> &get_ldex() const { return ldex; }
		const vector<int> &get_jdex() const { return jdex; }
		const vector<int> &get_mydex() const { return mydex; }
		const vector<int> &get_ldex_bar() const { return ldex_bar; }
		int get_lmax() const{ return lmax; }
		
	private:
		vector<int> kapdex;
		vector<int> ldex;
		vector<int> jdex;
		vector<int> mydex;
		vector<int> ldex_bar;
		const int lmax;
		const int kmax;
		
		// check whether lmax is consistent with kmax
		void check_length()
		{
			bool wrong_len = false;
			int len = int(kapdex.size());
			wrong_len = wrong_len || (kmax != len);
			len = int(ldex.size());
			wrong_len = wrong_len || (kmax != len);
			len = int(jdex.size());
			wrong_len = wrong_len || (kmax != len);
			len = int(mydex.size());
			wrong_len = wrong_len || (kmax != len);
			len = int(ldex_bar.size());
			wrong_len = wrong_len || (kmax != len);
			if (wrong_len)
			{
				cout << "Error: 2*(lmax+1)*(lmax+1) not equal to len of kapdex "
				<< endl;
				cout << "Error: len = " << len << "; 2*(lmax+1)*(lmax+1) = "
				<< 2*(lmax+1)*(lmax+1) <<endl;
				std::exit(EXIT_FAILURE);
			}
		}
		
		// assign values to the angular momemtum index matrices
		void assign_index()
		{
			int l, m;
			kapdex.push_back(-1); kapdex.push_back(-1);
			ldex.push_back(0); ldex.push_back(0);
			jdex.push_back(1); jdex.push_back(1);
			mydex.push_back(-1); mydex.push_back(1);
			ldex_bar.push_back(1); ldex_bar.push_back(1);
			
			for (l = 1; l<=lmax; l++)
			{
				// assign value for j=(l-1/2), where l, j are the angular momentum indices
				// l is the l index, m is the jm index
				for (m = -2*l+1; m<=2*l-1; m+=2)
				{
					kapdex.push_back(l);
					ldex.push_back(l);
					jdex.push_back(2*l-1);
					mydex.push_back(m);
					ldex_bar.push_back(l-1);
				}
				// assign value for j=(l+1/2), where l, j are the angular momentum indices
				for (m = -2*l-1; m<=2*l+1; m+=2)
				{
					kapdex.push_back(-(l+1));
					ldex.push_back(l);
					jdex.push_back(2*l+1);
					mydex.push_back(m);
					ldex_bar.push_back(l+1);
				}
			}
		}
		
	};



#if 0 // this is the old implementation. Commented by the if directive
	namespace
	{
		const int lmax = 6;
	} // here lmax is a private variable in the namespace (anonymous namespace used)
	
	const int kapdex[] =
	{
		-1,-1,
		1, 1,
		-2,-2,-2,-2,
		2, 2, 2, 2,
		-3,-3,-3,-3,-3,-3,
		3, 3, 3, 3, 3, 3,
		-4,-4,-4,-4,-4,-4,-4,-4,
		4, 4, 4, 4, 4, 4, 4, 4,
		-5,-5,-5,-5,-5,-5,-5,-5,-5,-5,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		-6,-6,-6,-6,-6,-6,-6,-6,-6,-6,-6,-6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		-7,-7,-7,-7,-7,-7,-7,-7,-7,-7,-7,-7,-7,-7
	};
	
	const int ldex[] =
	{
		0, 0,
		1, 1,
		1, 1, 1, 1,
		2, 2, 2, 2,
		2, 2, 2, 2, 2, 2,
		3, 3, 3, 3, 3, 3,
		3, 3, 3, 3, 3, 3, 3, 3,
		4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6
	};
	
	const int jdex[] =
	{
		1, 1,
		1, 1,
		3, 3, 3, 3,
		3, 3, 3, 3,
		5, 5, 5, 5, 5, 5,
		5, 5, 5, 5, 5, 5,
		7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7,
		9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
		9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
		11,11,11,11,11,11,11,11,11,11,11,11,
		11,11,11,11,11,11,11,11,11,11,11,11,
		13,13,13,13,13,13,13,13,13,13,13,13,13,13
	};
	
	const int mydex[] =
	{
		-1, 1,
		-1, 1,
		-3,-1, 1, 3,
		-3,-1, 1, 3,
		-5,-3,-1, 1, 3, 5,
		-5,-3,-1, 1, 3, 5,
		-7,-5,-3,-1, 1, 3, 5, 7,
		-7,-5,-3,-1, 1, 3, 5, 7,
		-9,-7,-5,-3,-1, 1, 3, 5, 7, 9,
		-9,-7,-5,-3,-1, 1, 3, 5, 7, 9,
		-11, -9, -7, -5, -3, -1,  1,  3,  5,  7,  9,  11,
		-11, -9, -7, -5, -3, -1,  1,  3,  5,  7,  9,  11,
		-13,-11, -9, -7, -5, -3, -1,  1,  3,  5,  7,  9,  11, 13
	};
	
	void print_indices()
	{	int length = 2*(lmax+1)*(lmax+1);
		
		cout << "kapdex: " << endl;
		for ( int i = 0; i < length; i++ )
		{
			cout << kapdex[i] << " " ;
		}
		cout << endl;
		
		cout << "ldex: " << endl;
		for ( int i = 0; i < length; i++ )
		{
			cout << ldex[i] << " " ;
		}
		cout << endl;
		
		cout << "jdex: " << endl;
		for ( int i = 0; i < length; i++ )
		{
			cout << jdex[i] << " " ;
		}
		cout << endl;
		
		cout << "mydex: " << endl;
		for ( int i = 0; i < length; i++ )
		{
			cout << mydex[i] << " " ;
		}
		cout << endl;
	}
#endif // endif of if 0
	
}
#endif /* Lambda_indices_hpp */
