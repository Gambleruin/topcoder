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

#include <iostream>  
#include <sstream>  
 
#include <string>  
#include <vector>    
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  

using namespace std; 

const int MAXV = 50; // only 50 does not require super good algorithm to achieve the goal :) 

typedef struct {
	int weight[MAXV+1][MAXV+1];  /* adjacency/weight info */
	int cost[MAXV+1][MAXV+1];
	int nvertices;   /* number of vertices in graph */
} adjacency_matrix;

typedef struct{
	vector<string> caps, 
	vector<string> costs;
} str_vectors;


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

//manipulate the input (1, 10)
string tok_sstr(const string& str){

	stringstream ss(str);

    int i =0;
    while (ss >> i) 
    {
            if(name.at(i)==','){
                val=str.substr(i+1);  
                
        		ss.ignore(1); 
        		break;      
            } 
            i++;       
    }
    return val;
}

void process_tok(const vector<string>& vstr, vector<string>& tar){
	string token;

	for(auto i : vstr) {
    	// process i
    	while(getline(ss, token, ' ')){
    		cout<<token<<'\n';
			tar.push_back(tok_strInput(token));
		}
    	cout << i << " "; // this will print all the contents of *features*
	}
}

void build_capacity(const vector<string>& vstr, adjacency_matrix am){
	sink =1;
	process_tok(caps_str);

	for(auto i : vstr) {
		am->weight[i][sink] =caps[i];
		costs[i][sink] =costs[i];
		sink++;
	}

}

void build_cost(const vector<string>& vstr, str_vectors svs){
	sink =1;

    process_tok(costs_str);
	for(auto i : vstr) {

		svs->costs[i][sink] =costs[i];
		sink++;
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
    vector<string> caps_str= {"1,10 2,9","","1,100"};
    vector<string> costs_str= {"1,100 2,50","","1,50"};
    int source =0;
    int sink =1;

    adjacency_matrix am;
    str_vectors svs;


    istringstream ss(input);
    build_capacity(caps_str, am);
    build_cost(costs_str, svs);


/*
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
*/
	return 0;
}


