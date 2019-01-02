//
//  AtomInfo.hpp
//  
//
//  Created by Xianglin Liu on 12/31/18.
//
//

#ifndef AtomInfo_hpp
#define AtomInfo_hpp

#include "Array3d.hpp"
#include "RmeshGrid.hpp"
#include <vector>
#include <complex>
#include <iostream>
#include <string>
#include <sstream>

using Array3d::Array3d;
using RmeshGrid::Rmesh0;
using std::vector;
using std::string;
using std::complex;

namespace AtomInfo
{
	// The global information is encapsulated to avoid changes;
	class Global_info
	{
		public:
			// default constructor
			Global_info(): num_atom(0), name_pot_file(""), is_magnetic(0) {;}
			// constructor to be initialized with explicit values
			Global_info(int num_atom_in, string name_pot_file_in, int is_magnetic_in):
			num_atom(num_atom_in), name_pot_file(name_pot_file_in), is_magnetic(is_magnetic_in)
			{;}
			// constructor to be initialized with a vecotr of stringes (input_info);
			Global_info(const vector<string> &input_info)
			{
				num_atom = std::stoi(input_info[0]);
				name_pot_file = input_info[1];
				is_magnetic = std::stoi(input_info[2]);
			}
			
			int get_num_atom() const { return num_atom; }
			string get_name_pot_file() const { return name_pot_file; }
			int get_is_magnetic() const { return is_magnetic; }
			
		private:
			int num_atom; // the number of atoms in the node
			string name_pot_file; // the file to store the potentials
			int is_magnetic; // the system is magnetic or not};
	};

	struct Atom_info
	{
		public:
			Atom_info():
			element(""), lmax_kkr(0), rstart(0), rend(0), nr(0) {;}
		
			Atom_info(const vector<string> &input_atom, Global_info g_info_in):
			g_info(g_info_in)
			{
				element = input_atom[0];
				lmax_kkr = std::stoi(input_atom[1]);
				rstart = std::stod(input_atom[2]);
				rend = std::stod(input_atom[3]);
				nr = std::stoi(input_atom[4]);
				
				// convert the list_vl string to int numbers;
				string buf;
				std::stringstream ss(input_atom[5]);
				while (ss >> buf)
					list_vl.push_back(std::stoi(buf));
				
				rmesh = Rmesh0( nr, rstart, rend );
				pot = read_pot();
			}
		
			const Global_info g_info;
		
			string element;
			int lmax_kkr;
			double rstart;
			double rend;
			int nr;
			vector<int> list_vl;

			Rmesh0 rmesh;
			Array3d< complex<double> > pot;
			
		private:
			Array3d< complex<double> >  read_pot()
			{
				string pot_file = g_info.get_name_pot_file();
				int is_mag = g_info.get_is_magnetic();
				int nspin = (is_mag > 0)? 2 : 1;
				int length = list_vl.size();
				Array3d< complex<double> > pot_tmp( length, nr, nspin );
				// to be continued ...
				return pot_tmp;
			}
		
	};
	
	void init_info(const vector<string> &input_info,
	Global_info &global0, vector<Atom_info> &atoms)
	{
		int num_atom_in = std::stoi(input_info[0]);
		string name_pot_file_in = input_info[1];
		int is_magnetic_in = std::stoi(input_info[2]);
		global0 = Global_info(num_atom_in, name_pot_file_in, is_magnetic_in);
		
		int j_max = 6; // number of lines of information for each atom
		for (int i=0; i<num_atom_in; i++)
		{
			vector<string> tmp;
			for (int j=0; j<j_max; j++)
			{
				tmp.push_back(input_info[3+i*j_max+j]);
			}
			atoms.push_back( Atom_info(tmp, global0) );
		}
	}	
}

#endif /* AtomInfo_hpp */
