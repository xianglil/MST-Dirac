//
//  IntegerFactors.hpp
//  
//
//  Created by Xianglin Liu on 1/1/19.
//
//

#ifndef IntegerFactors_hpp
#define IntegerFactors_hpp

#include <vector>

using std::vector;

namespace IntegerFactors {
	struct Factors
	{
		public:
		
		Factors(int lmax_in = 6):
		lmax(lmax_in), kmax( (lmax_in+1)*(lmax_in+1) ),
		jmax( (lmax_in+1)*(lmax_in+2)/2 ),
		lofk(kmax, 0), mofk(kmax, 0), jofk(kmax, 0),
		lofj(jmax, 0), mofj(jmax, 0), kofj(jmax, 0)
		
		{
			int jl = 0;
			int kl = 0;
			for (int l=0; l<=lmax; l++)
			{
				int n = (l+1)*(l+2)/2-l-1;
				for (int m=-l; m<=l; m++)
				{
					lofk[kl] = l;
					mofk[kl] = m;
					if (m>=0)
					{
						jofk[kl] = n+m;
					}
					else
					{
						jofk[kl] = n-m;
					}
					kl++;
				}
				for (int m=0; m<=l; m++)
				{
					lofj[jl]=l;
					mofj[jl]=m;
					kofj[jl]=(l+1)*(l+1)-l+m-1;
					jl++;
				}
			}
			
		}
		
		int lmax;
		int kmax;
		int jmax;	
		vector<int> lofk;
		vector<int> mofk;
		vector<int> jofk;
		vector<int> lofj;
		vector<int> mofj;
		vector<int> kofj;
	};
}

#endif /* IntegerFactors_hpp */
