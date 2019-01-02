//
//  AtomInfo.cpp
//  
//
//  Created by Xianglin Liu on 12/31/18.
//
//

#include "AtomInfo.hpp"
#include <string>
#include <vector>

using AtomInfo::Global_info;
using AtomInfo::Atom_info;
using AtomInfo::init_info;
using std::vector;
using std::string;
using std::cout;
using std::endl;

void print_global_info(const Global_info &globalInfo)
{
	cout << "***********************************************" << endl;
	cout << "The global atomic information is" << endl;
	cout << "get_num_atom()=" << globalInfo.get_num_atom() << endl;
	cout << "get_name_pot_file()=" << globalInfo.get_name_pot_file() << endl;
	cout << "get_is_magnetic()=" << globalInfo.get_is_magnetic() << endl;
	cout << "***********************************************" << endl;
}

void print_atom_info(const Atom_info & atomInfo)
{
	cout << "***********************************************" << endl;
	cout << "atomInfo.element=" << atomInfo.element << endl;
	cout << "atomInfo.lmax_kkr=" << atomInfo.lmax_kkr << endl;
	cout << "atomInfo.rstart=" << atomInfo.rstart << endl;
	cout << "atomInfo.rend=" << atomInfo.rend << endl;
	cout << "atomInfo.nr=" << atomInfo.nr << endl;
	int len = atomInfo.list_vl.size();
	cout << "len=" << len << endl;
	for (int j=0; j<len; j++)
	{
		cout << "atomInfo.list_vl " << j << " =" << atomInfo.list_vl[j] << endl;
	}
	cout << "***********************************************" << endl;
}

void print_test_Atom_info()
{
	vector<string> input_atom;
	input_atom.push_back("2");
	input_atom.push_back("Cu_pot_mt_new");
	input_atom.push_back("0");
	input_atom.push_back("Cu");
	input_atom.push_back("4");
	input_atom.push_back("1.0E-05");
	input_atom.push_back("3.0E-0");
	input_atom.push_back("1030");
	input_atom.push_back("1");
	
	input_atom.push_back("Fe");
	input_atom.push_back("4");
	input_atom.push_back("1.0E-05");
	input_atom.push_back("3.0E-0");
	input_atom.push_back("1030");
	input_atom.push_back("1");
	
	Global_info global0;
	vector<Atom_info> atoms;
	init_info(input_atom, global0, atoms); // test of init_info
	print_global_info(global0); // print global info
	cout << "test of direct initialization" << endl;
	Global_info global1(input_atom); // test of direct initialization
	print_global_info(global1);
	
	for (int i=0; i<global0.get_num_atom(); i++)
	{
		Atom_info atomInfo = atoms[i];
		cout << "atomic index is " << i << endl;
		print_atom_info(atomInfo); // print atom info
	}
}


int main()
{
	print_test_Atom_info();
}
