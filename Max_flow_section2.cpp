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

class RookAttack
{
public:
    // reduction to max_flow using Ford–Fulkerson algorithm
	int bipartite_matching(int rows, int cols, vector <string> cutouts){
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




