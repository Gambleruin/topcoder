/*
topcoder
Max_flow_section2.cpp

sources from:
https://www.topcoder.com/community/data-science/data-science-tutorials/maximum-flow-section-2/
https://www.topcoder.com/community/data-science/data-science-tutorials/introduction-to-graphs-and-their-data-structures-section-2/

problems statement:
http://community.topcoder.com/stat?c=problem_statement&pm=2852&rd=5075
problem: graduation, rook attack

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

int rows, cols;

void Print(int *arr, unsigned size)
{
	for (int i =0; i<size; i++){
		cout <<arr[i]<<endl;
	}

}

int find_path(int where)  
{  
    if (-1 == where) {      
        return 1;  
    }  
    for (int i = 0; i < cols; i++) {  
        if (cut[where][i] || v[i]) {  
                continue;  
            }  
            v[i] = true;  
            if (find_path(col_match[i])) {  
                col_match[i] = where;      
                return 1;  
            }  
    }  
    return 0;  
} 

class MaxFlowImplementation
{
public:
    // reuction to max_flow using Ford–Fulkerson algorithm
	int bipartite_matching(int rows, int cols, vector <string> cutouts){
		int res = 0;  
        this->rows = rows;  
        this->cols = cols;  
        memset(cut, 0, sizeof(cut));  
        // 对字符串进行处理  
        string S;  
        for (int i = 0; i < cutouts.size(); i++) {  
            S += cutouts[i] + ", ";  
        }             
        for (int i = 0; i < S.size(); i++) {  
            if (',' == S[i]) {  
                S[i] = ' ';  
            }  
        }  
        int r, c;  
        stringstream ss(S);  
        while (ss >> r >> c) {  
            cut[r][c] = true;  
        }  
        memset(col_match, -1, sizeof(col_match));  
        for (int i = 0; i < rows; i++) {  
            memset(v, 0, sizeof(v));  
            res += find_path(i);        // dfs找增广路径  
        }  
        return res;  
    }  
};


 /*
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
*/

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
		vector<vector<int> > v(n);
		vector<vector<bool> > _v(n, vector<bool> (k, true));
		
		for(int i = 0; i < cuts.size(); i++)
		{
			istringstream is(cuts[i]);
			int a, b;
			char c;
			while(is >> a >> b)
			{
				_v[a][b] = false;
				is >> c;
			}
		}
 
		for(int i = 0; i < n; i++)
			for(int j = 0; j < k; j++)
				if(_v[i][j])
					v[i].push_back(j+n);
 		MaxFlowImplementation obj;
		return obj.find_max_matching(v, n, k).size();
        }
};

typedef int (RookAttack::*METHOD)(int, int, vector<string>);

int main(){
	int row =2;
	int col =2;
	vector<string> cuts= {"0 0","0 1","1 1","1 0"};
	RookAttack* obj =new RookAttack;
	METHOD Action =&RookAttack::howMany;
	int res =(obj->*Action)(row, col, cuts);
	printf("%i\n\n", res);
	delete obj;
    return 0;
}




