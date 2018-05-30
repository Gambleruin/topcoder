/*
TCO 2003 - Semifinal Round 4 Division 1 [topcoder]
problem:
PipePath

problem statement:
https://community.topcoder.com/stat?c=problem_statement&pm=1889&rd=4709
Difficult level: medium

source from:
https://community.topcoder.com/tc?module=Static&d1=tournaments&d2=tco03&d3=summary&d4=room4_analysis
trust me, the author is brilliant :), so now, I have an idea of the implementation 
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

const int MAXV = 50; // only 50 does not require super good algorithm to achieve the goal :) 

typedef struct {
	int weight[MAXV+1][MAXV+1];  /* adjacency/weight info */
	int cost[MAXV+1][MAXV+1];
	int nvertices;   /* number of vertices in graph */
} adjacency_matrix;

void initialize_adjacency_matrix(adjacency_matrix *g){
	int i, j; /* counters */
	g->nvertices =0;
	for(i =1; i<MAXV; i++)
		for(j =1; j<=MAXV; j++)
			g->weight[i][j] =MAXINT;
}

void read_adjacency_matrix(adjacency_matrix *g, bool directed){
	int i;      /* counter*/
	int m;      /* number of edges */
	int x,y,w;  /* placeholder for edge/weight */

	initialize_adjacency_matrix(g);
	for(i =1; i<=m; i++){
		g->weight[x][y] =w;
		if(directed ==FALSE) g->weight[y][x] =w;
	}
}

void floyd(adjacency_matrix *g){
	int i, j;     /* dimension counters */
	int k;        /* intermediate vertex counter */
	int through_k;/* distance through vertex k */

	for (k =1; k<=g->nvertices; k++)
		for(i =1; i<=g->nvertices; i++)
			for(j =1; j<=g->nvertices; j++){
				through_k =g->weight[i][k]+g->weight[k][j];
				if(through_k <g->weight[i][j])
					g->weight[i][j] =through_k;
			}
}

//manipulate the input 
void tok_strInput(const std::string& input){
	istringstream ss(input);
	string token;
	while(getline(ss, token, ' ')){
		cout<<token<<'\n';
	}
}

/*
double ratio = 0;
	foreach(unique capacity cap){
		find the shortest path from source to sink,
		   each of whose edges has a capacity of at least cap
		if(there is some path){
			ratio = max(ratio, cap/pathLength)
		}
	}
	return ratio;
*/

int main(){
    vector<string> caps= {"1,10 2,9","","1,100"};
    vector<string> costs= {"1,100 2,50","","1,50"};
    int source =0;
    int sink =1;

    memset(caps, 0, sizeof(caps));  
    memset(costs, 0, sizeof(costs)); 
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
                 
        }  
	return 0;
}


