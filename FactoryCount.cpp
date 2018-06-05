/*
TCCC 2006, Round 1B Medium

For each city, keep a bit-set of the neighbouring cities. 
Once the part-building factories have been chosen (recursively), 
ANDing together these bit-sets will give a bit-set which describes 
the possible locations of the part-assembly factories. If this 
bit-set has k bits, then there are kCm ways to allocate the part-assembly 
factories.

problem name:
FactoryCounting

problem statement:
http://community.topcoder.com/stat?c=problem_statement&pm=6725&rd=10100

problem difficulty:
medium

implementation sources:
https://community.topcoder.com/tc?module=Static&d1=match_editorials&d2=tccc06_online_rd_1b

*/
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <queue>
#include <complex>
 
using namespace std;

/*
      // element cnk[i][j] contains the value C(i, j).
        vector > cnk; 
        // element connection[i] contains the bitmask, representing 
        // all the factories connected to the i-th factory
        vector connection; 
        // computes the number of 1's in the binary code of number i.
        int ones(int n) { return n ? 1 + ones(n & (n - 1)) : 0;} 
        // the core method, which tries adding the current factory or skipping it.
        long long go(int factory, int count, int assembly) { 
            if (count == m)
                return cnk[ones(assembly)][n];
            if (factory >= N) 
                return 0;
            // move to the next factory
            return go(factory + 1, count, assembly) + 
                go(factory + 1, count + 1, assembly & connection[factory]); 
// add the current factory to the list, updating the total count and connections list
        }
        long long count(int n, int m, vector  county) 
            { 
            N = county.size(); // the total number of cities
            this.m = m; this.n = n;
            if (m + n > N) // we definitely can not build the complex
                return 0;
            connection = vector(N, 0);
            for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) 
                if (county[i][j] == 'Y') connection[i] |= (1 << j);
            cnk= vector >(N + 1, vector(N + 1, 0));
            for (int i = 0; i < N; i++) cnk[i][0] = 1;
            for (int i = 1; i < N; i++) for (int j = 1; j < N; j++) 
        cnk[i][j] = cnk[i - 1][j - 1] + cnk[i - 1][j];
            return go(0, 0, (1 << N) - 1); 
// start from factory 0, 
//with total of 0 factories added to the set, 
// with all factories "connected" to our empty set.
            }
*/

// computes the number of 1's in the binary code of number i.
int ones(int n) { 
	return n ? 1 + ones(n & (n - 1)) : 0;
} 

template<class T>
void splitstr(const string &s, vector<T> &out){
	istringstream in(s);
	T tmp;

	out.clear();
	while(in >>tmp)
		out.push_back(tmp);

}

class FactoryCounting
{
public:
	long long count(int n, int m, vector <string> county);
};





