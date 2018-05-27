/*
topcoder
Max_flow_section2.cpp

sources from:
https://www.topcoder.com/community/data-science/data-science-tutorials/maximum-flow-section-2/
https://www.topcoder.com/community/data-science/data-science-tutorials/introduction-to-graphs-and-their-data-structures-section-2/

problems statement:
http://community.topcoder.com/stat?c=problem_statement&pm=2852&rd=5075
problem: graduation, rook attack

the bfs might be preferred here is becasue 
The next best thing in the matter of simplicity 
is a breadth-first search (BFS). Recall that 
this search usually yields the shortest path 
in an un-weighted graph. Indeed, this also applies 
here to get the shortest augmenting path from the 
source to the sink.
*/

#include <iostream> 
#include <sstream> 
#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <queue> 
#include <set> 
#include <map> 

#include<vector>
#include<utility>

using namespace std;
/*
An implementation point of view is in place. We could implement the maximum bipartite matching just like in the pseudocode given 
earlier. Usually though, we might want to consider the particularities of the problem before getting to the implementation part, 
as they can save time or space. In this case, we could drop the 2-dimensional array that stored the residual network and replace 
it with two one-dimensional arrays: one of them stores the match in set B (or a sentinel value if it doesn’t exist) for each element 
of set A, while the other is the other way around. Also, notice that each augmenting path has capacity 1, as it contributes with just 
a unit of flow. Each element of set A can be the first (well, the second, after the super-source) in an augmenting path at most once, 
so we can just iterate through each of them and try to find a match in set B. If an augmenting path exists, we follow it. This might 
lead to de-matching other elements along the way, but because we are following an augmenting path, no element will eventually remain 
unmatched in the process.
*/

class MaxFlowImplementation
{
public:
	vector<vector<int> > g;
	vector<bool> used;
	int n, k;
 
	bool find_path(int a, int b) 
        {
		if(a == b) return true;
		if(used[a]) return false;
		used[a] = true;
		for(int i = 0; i < n+k+2; i++) 
			if(g[a][i] > 0 && find_path(i, b))
                        {
				g[a][i]--;
				g[i][a]++;
				return true;
			}
		return false;
	}
 
	vector<pair<int, int> > find_max_matching(vector<vector<int> > &v, int _n, int _k)
        {
		//v[i] is a list of adjacent vertices to vertex i, where i is from left part and v[i][j] is from right part
		n = _n;
		//n is number of vertices in left part of graph
		k = _k;
		//k is number of vertices in right part of graph
 
		g = vector<vector<int> >(n+k+2, vector<int>(n+k+2));
		//g[i][j] = 1 if there is edge between vertex i from left part 
		//and vertex j from right part
		for(int i = 0; i < v.size(); i++)
                    for(int j = 0; j < v[i].size(); j++)
                        g[i][v[i][j]] = 1;
		int S = n+k;
		int T = n+k+1; 
		for(int i = 0; i < n; i++)
			g[S][i] = 1;
		for(int i = 0; i < k; i++)
			g[n+i][T] = 1;
 
		vector<vector<int> > _g(g);
 
		used = vector<bool> (n+k+2, false);
		while(find_path(S, T))
			fill(used.begin(), used.end(), false);
 
		vector<pair<int, int> > res;
		for(int i = 0; i < n; i++)
			for(int j = n; j < n+k; j++)
				if(g[i][j] < _g[i][j])
					res.push_back(make_pair(i, j));
 
		return res;
	}
};

class RookAttack 
{
public:
        int howMany(int n, int k, vector <string> cuts) 
        {
		vector<vector<int> > g(n);
		vector<vector<bool> > _g(n, vector<bool> (k, true));
		
		for(int i = 0; i < cuts.size(); i++)
		{
			istringstream is(cuts[i]);
			int a, b;
			char c;
			while(is >> a >> b)
			{
				_g[a][b] = false;
				is >> c;
			}
		}
 
		for(int i = 0; i < n; i++)
			for(int j = 0; j < k; j++)
				if(_g[i][j])
					g[i].push_back(j+n);
 
		return obj.find_max_matching(g, n, k).size();
        }
};

typedef double (RookAttack::*METHOD)(vector<int>, int, vector<int>);

int main(){
   return 0;
}




