//
//  ReadInput.cpp
//  
//
//  Created by Xianglin Liu on 12/27/18.
//
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "ReadInput.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::fstream;
using namespace InputFunc;

template <class T>
void print_test_vector(vector<T>& vec_in)
{
	for ( int i=0; i<vec_in.size(); i++ )
	{
		cout << vec_in[i] << endl;
	}
	
}

bool InputFunc::is_comment(string val)
{
	int n = val.size();
	bool judge = false;
	for (int i=0; i<n; i++)
		if (val[i]=='#')
		{
			judge = true;
			break;
		}
		else if (isspace(val[i]))
		{
			continue;
		}
		else
		{
			break;
		}
	return judge;
}

vector<string> InputFunc::read_input( string filename )
{
	vector<string> input_info;
	string text;
	fstream file;
	file.open(filename, std::ios::in);
	while ( getline( file, text ) )
		if ( !is_comment(text) && !text.empty() )
			//remove line start with # and empty line
		{
			input_info.push_back(text);
		}
	file.close();
	return input_info;
}

int main( int argc, char *argv[] )
{
	string filename;
	if (argc>1)
		filename = argv[1]; // name of input file
	else
		filename = "input_Cu";
	vector<string> input_info;
	input_info = read_input( filename);
	print_test_vector(input_info);
	return 0;
}