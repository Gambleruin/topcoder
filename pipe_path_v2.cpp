/*
mei you
*/

#include <string>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

const int MAXV = 50; // only 50 does not require super good algorithm to achieve the goal :) 
const int imax = numeric_limits<int>::max();


typedef struct {
  int weight[MAXV+1][MAXV+1];  /* adjacency/weight info */
  int cost[MAXV+1][MAXV+1];
  int nvertices;   /* number of vertices in graph */
} ADJACENCY_MATRIX;

//one way to validate if it prints out the correct weight matrix for graph
void print_matrix(ADJACENCY_MATRIX *a){
  
  int val;
  for (int i =0; i<3; i++){
    for(int j =0; j<3; j++){
      val =a->weight[i][j];
      printf("%d%d\n%d\n",i, j, val);
    }
  }

}
void print(vector<int>  str){
  for (auto i = str.begin(); i != str.end(); ++i){
    printf("\n wewanna know what is isis???");
    cout << *i << ' ';
  }
}

void prints(vector<string>  str){
  for (auto i = str.begin(); i != str.end(); ++i){
    printf("\n wewanna know aaa???");
    cout << *i << ' ';
  }
}

vector< string > tokenize( string a, string b ) {
  //printf("\n\n\n\n\n\n\n\n");
  //printf("%s", b.c_str());
  const char *q = a.c_str();
  /*
  while( count( b.begin(), b.end(), *q ) ) {

    //printf("the char is: %s", q);
    q++;
  }
  */
  vector< string > oot;
  while( *q ) {
    const char *e = q;
    while( *e && !count( b.begin(), b.end(), *e ) ) {
      //printf("the previous char is: %s\n\n\n", e);
      e++;
    }
    oot.push_back( string( q, e ) );
    //print(oot);
    //printf("\n\n\n\n\n\n\n\n");
    q = e;

    while( count( b.begin(), b.end(), *q ) ) {
      //printf("was I here?");
      //printf("the char is: %s\n", q);
      q++;
    }
  }
  return oot;
}

vector< int > sti( const vector< string > &a ) {
  vector< int > oot;
  for( int i = 0; i < a.size(); i++ ) {
    //printf("\n\n\n\n\n\n\n was I being here \n\n\n\n\n\n\n\n\n\n");
    oot.push_back( atoi( a[ i ].c_str() ) );
  }
  return oot;
}

// main algorithm used for solving the problem
void initialize_adjacency_matrix(ADJACENCY_MATRIX *g){
  int i, j; 
  g->nvertices =0;
  for(i =1; i<MAXV; i++)
    for(j =1; j<=MAXV; j++)
      g->weight[i][j] =imax;
}

void read_adjacency_matrix(ADJACENCY_MATRIX *g, bool directed){
  int i;     
  int m;      
  int x,y,w;  

  initialize_adjacency_matrix(g);
  for(i =1; i<=m; i++){
    g->weight[x][y] =w;
    if(directed ==false) g->weight[y][x] =w;
  }
}

void floyd(ADJACENCY_MATRIX *g){
  int i, j;    
  int k;        
  int through_k;

  for (k =1; k<=g->nvertices; k++)
    for(i =1; i<=g->nvertices; i++)
      for(j =1; j<=g->nvertices; j++){
        through_k =g->weight[i][k]+g->weight[k][j];
        if(through_k <g->weight[i][j])
          g->weight[i][j] =through_k;
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

class pipe_path{
public:
  double pipe_path(){
    double ratio =0;
    for(){

    }

  }
}

int main(){

vector<string> caps_str= {"1,10 2,9","","1,100"};
vector<string> costs_str= {"1,100 2,50","","1,50"};

vector<int> capacity;
vector<int> costs;

memset( &capacity, 0, sizeof( capacity ) );
memset( &costs, 0, sizeof( costs ) );

ADJACENCY_MATRIX ad_M;
memset( &ad_M, 0, sizeof( ADJACENCY_MATRIX ) );

for( int i = 0; i < caps_str.size(); i++) {
      vector< string > ica = tokenize( caps_str[ i ], " " );      
      vector< string > cca = tokenize( costs_str[ i ], " " );
      for( int j = 0; j < ica.size(); j++ ) {
        vector< int > icb = sti( tokenize( ica[ j ], "," ) );
        //as the first element will be the sink and second one is the capacity
        
        //initialize value for weight matrix 
        ad_M.weight[i][icb[0]] =icb[1];
        capacity.push_back(icb[1]);
        vector< int > ccb = sti( tokenize( cca[ j ], "," ) );
        // same thing goes with cost list
        ad_M.cost[i][ccb[0]] =ccb[1];
        costs.push_back(ccb[1]); 
        //printf("%d\n%d\n%d\n\n", i,icb[0], ad_M.weight[i][icb[0]] );
        //printf("%d\n\n", ad_M.weight[i][icb[0]]);
        //printf("easy easy\n\n");
        //printf("%d\n\n", ad_M.cost[i][ccb[0]]);

        //printf( "%s, %s, %d, %d,\n", ica[i+1].c_str(), cca[i+1].c_str(), i, j);
        
      }
      
      //printf("outter loop another one turn\n\n");
}
//print_matrix(&ad_M);
//print(capacity);
print(costs);

return 0;
}



