//
//  ReadInput.hpp
//  
//
//  Created by Xianglin Liu on 12/27/18.
//
//

#ifndef ReadInput_hpp
#define ReadInput_hpp

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace InputFunc
{
	bool is_comment(string val);
	
	vector<string> read_input( string filename );
	
}

#endif /* ReadInput_hpp */
