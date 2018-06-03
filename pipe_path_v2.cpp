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


//this might not be needed in the future 
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

/*
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

void (ADJACENCY_MATRIX *g){
  int i, j;    
  int k;        
  int through_k;

  vector<vector<int>> next(3);

  for (k =1; k<=g->nvertices; k++)
    for(i =1; i<=g->nvertices; i++)
      for(j =1; j<=g->nvertices; j++){
        through_k =g->weight[i][k]+g->weight[k][j];
        if(through_k <g->weight[i][j])
          g->weight[i][j] =through_k;
      }
}
*/

void solve(vector<vector<int>> w_s, const int num_vertices){
  // distance in this case is the cost of the pipe
  vector<vector<int>> dist(num_vertices);
  for(int& dim: dist){
    for(int i =0; i< num_vertices; ++i){
      dim.push_back(imax);
    }
  }
  for(int &w: w_s){
    dist[w[0] -1][w[1] -1] =w[2];
  }

  vector<vector<int>> next(num_vertices);
  for(int i =0; i<num_vertices; ++i){
    for(int j =0; j<num_vertices; ++j){
      next[i].push_back(0);
    }
    for(int j =0; j<num_vertices; ++j){
      if(i !=j){
        next[i][j] =j+1;
      }
    }
  }
  //floyd_reconstruct all paths 
  for (auto k = 0; k < num_vertices; ++k) {
    for (auto i = 0; i < num_vertices; ++i) {
      for (auto j = 0; j < num_vertices; ++j) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }

}

void print(vector<vector<double>> dist, vector<vector<int>> next){
  cout<<"(pair, dist, path)"<<endl;
  const int size =next.size();
  for(int i =0; i<size; ++i){
    for(int j =0; j<size; ++j){
      if(i !=j){
        int u =i+1;
        int v =j+1;
        cout <<"("<<u<<"->"<<v<<", "<<dist[i][j]<<",";
        stringstream path;
        path<<u;
        do{
          u =next[u -1][v -1];
          path <<" ->"<< u;
        } while(u !=v);
        cout<<path.str()<< ")"<<endl;
      }
    }
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
  double pipe_path( vector<int> *c, int source, int sink, ADJACENCY_MATRIX *a){
    double ratio =0;
    for(int x =0; x< c->size(); ++x){
      //unique capacity cap
      int value =(*c)[x];
    }
    return 0;
    
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



