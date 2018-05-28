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

using namespace std;
//global variables for dfs
/*
bool cut[30][30]; 
int col_match[30];  
bool v[30]; 
*/

bool cut[30][30]; 
int cap[30][30];  
int from[30];      
bool v[30];       

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

	//use bfs to find path (gredily ) with Ford–Fulkerson algorithm
	int find_path_gred()
	{
		//the row-vertex that precedes x in the path
		/*
		vector<int> from;
		memset(from, -1, sizeof(from));
		from[source] =source;
		deque <int> q;
		q.push_back(source);

		int found_path =0;		
		while (!found_path && !q.empty()){

		}
		*/

		memset(v, 0, sizeof(v));  
        memset(from, -1, sizeof(from));  
        queue <int> Q;  
        int start = rows, end = rows + cols + 1; 
        v[start] = true;  
        int where;  
 
        bool found_path= false;  
        while (!Q.empty()) {  
            where = Q.front();  
            Q.pop();  
            for (int i = 0; i <= rows + cols + 1; i++) {  
                if (cap[where][i] > 0 && !v[i]) {  
                    from[i] = where;  
                    v[i] = true;  
                    if (i == end) {  
                        found_path = true;  
                        break;  
                    }  
                    Q.push(i);  
                }  
            }  
            if (found_path) {  
                break;  
            }  
        }  

        int path_cap = INF;  
        where = end;  
        while (from[where] != -1) {  
            int pre = from[where];  
            path_cap = min(path_cap, cap[pre][where]);  
            where = pre;  
        }  

        where = end;  
        while (from[where] != -1) {  
            int pre = from[where];  
            cap[pre][where] -= path_cap;  
            cap[where][pre] += path_cap;  
            where = pre;  
        }  
          
        return (path_cap == INF ? 0 : path_cap); 
	}
	// almost identical, but you know I am lazy
	int b_match(int rows, int cols, vector <string> cutouts){
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
            cut[r][c + rows + 1] = true;  
        }  
  
        memset(cap, 0, sizeof(cap));  
        for (int i = 0; i < rows; i++) {  
            for (int j = rows + 1; j < rows + cols + 1; j++) {  
                if (!cut[i][j]) {  
                    cap[i][j] = 1;       
                }  
                cap[j][rows + cols + 1] = 1;    
            }  
            cap[rows][i] = 1;   
        }  
        int add;  
        while ( (add = bfs()) != 0 ) {  
            res += add;  
        }  
        return res;  

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
	METHOD Action =&RookAttack::b_match;
	int res =(obj->*Action)(row, col, cuts);
	printf("\n%i\n\n", res);
	delete obj;
    return 0;
}




