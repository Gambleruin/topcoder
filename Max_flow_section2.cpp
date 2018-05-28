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
#include <algorithm>  
#include <functional>  
#include <numeric>  
#include <utility>  
#include <iostream>  
#include <sstream>  
#include <iomanip>  
  
#include <bitset>  
#include <string>  
#include <vector>  
#include <stack>  
#include <deque>  
#include <queue>  
#include <set>  
#include <map>  
  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>  
#include <ctime>  
#include <climits> 
#include <limits> 

using namespace std;
//global variables for dfs

bool cut[30][30]; 
int col_match[30];  
bool v[30]; 

int cap[30][30];  
int from[30];   

double inf = std::numeric_limits<double>::infinity();   
      

void Print(int *arr, unsigned size)
{
	for (int i =0; i<size; i++){
		cout <<arr[i]<<endl;
	}
}

class RookAttack
{

public:	
	int rows, cols;

	// use dfs
	int find_path(int source)  
	{  
		/*
		no argumenting path implies maximum matching
		https://www.cs.dartmouth.edu/~ac/Teach/CS105-Winter05/Notes/kavathekar-scribe.pdf
		*/

    	if (-1 == source) {  
    		 
        	return 1;  
    	}  
    	for (int i = 0; i < cols; i++) {  
        	if (cut[source][i] || v[i]) {  
                	continue;  
            	}  
            	v[i] = true;  
            	if (find_path(col_match[i])) {  
                	col_match[i] = source;     
                	return 1;  
            	}  
    	}  
    return 0;  
	} 

    // reduction to max_flow using  dfs
	int d_match(int rows, int cols, vector <string> cutouts){
		int res = 0;  
        this->rows = rows;  
        this->cols = cols; 

        memset(cut, 0, sizeof(cut));   
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
            res += find_path(i);         
        }  
        return res;  
    }  
};

typedef int (RookAttack::*METHOD)(int, int, vector<string>);

int main(){
	int row =8;
	int col =8;
	vector<string> cuts= {};
	RookAttack* obj =new RookAttack;
	METHOD Action =&RookAttack::d_match;
	int res =(obj->*Action)(row, col, cuts);
	printf("\n%i\n\n", res);
	delete obj;
    return 0;
}




