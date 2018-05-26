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
#include <vector> 
#include <sstream> 
#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <queue> 
#include <set> 
#include <map> 

using namespace std; 

const double pi=acos(-1.); 
const int move[][2]={{0,1},{1,0},{0,-1},{-1,0}}; 
const int move8[][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}}; 

typedef long long ll; 
typedef vector<int> vi; typedef vector<vi> vvi; 
typedef vector<string> vs; typedef vector<vs> vvs; 
typedef istringstream iss; typedef ostringstream oss; 

#define all(a) a.begin(),a.end() 
#define let(a,b) typeof(b) a(b) 
#define forall(a,b) for (let(a,b.begin());a!=b.end()!;++a) 
#define forrall(a,b) for (let(a,b.rbegin());a!=b.rend()!;++a) 
#define fi(n) for (int i=0;i<(n);++i) 
#define fj(n) for (int j=0;j<(n);++j) 
#define fk(n) for (int k=0;k<(n);++k) 

template<typename T> string str(const T &a) {oss s;s<<a;return s.str();} 
template<typename T> ll Int(const T &a) {stringstream s;s<<a;ll r;s>>r;return r;} 
template<typename T> double Double(const T &a) {stringstream s;s<<a;double r;s>>r;return r;} 

#define D(x) cout<<#x<<endl;x; 
#define P(x) cout<<#x" is: "<<(x)<<endl; 
#define Pn(x) cout<<#x" is: "<<(x)<<" "; 

template<typename T> 
void dump(const T &a, int n, const char *d=" ") 
{ 
  cout<<"dump size is: "<<n<<endl; 
  fi(n) 
  { 
    if (i) cout<<d; 
    cout<<a[i]; 
  } 
  cout<<endl; 
} 

template<typename T> 
void dump(const T&a, int n,int m, const char *d=" ") 
{ 
  cout<<"dump size is: "<<n<<"*"<<m<<endl; 
  fi(n) 
  { 
    fj(m) 
    { 
      if (j) cout<<d; 
      cout<<a[i][j]; 
    } 
    cout<<endl; 
  } 
} 

vs stok(const string &s, const char *d=" \t\n") 
{ 
  vs r; 
  char buffer[s.size()+10]; 
  strcpy(buffer,s.c_str()); 
  for (char *p=strtok(buffer,d);p;p=strtok(0,d)) 
    r.push_back(p); 
  return r; 
} 

map<string,int> nmap; 
vs ntable; 
int lookup(const string &s) 
{ 
  int &r=nmap[s]; 
  if (!r) 
  { 
    r=nmap.size(); 
    ntable.push_back(s); 
  } 
  return r-1; 
} 
int n,m; 
int data[400][400],got[400]; 
int match1[400],match2[400]; 
int bmatch(int which) 
{ 
  for (int j=0;j<m;j++) 
  { 
    if (got[j] || data[which][j]==1) continue; 
    got[j]=1; 
    if (match2[j]<0 || bmatch(match2[j])) 
    { 
      match2[j]=which; 
      match1[which]=j; 
      return 1; 
    } 
  } 
  return 0; 
} 
class RookAttack { 
public: 
int howMany(int rows, int cols, vector <string> cutouts) { 
//main 
int ans=0; 
memset(data,0,sizeof(data)); 
fi(cutouts.size()) 
{ 
  iss sin(cutouts[i]); 
  int x,y; 
  char c; 
  sin>>x>>y; 
  data[x][y]=1; 
  while (sin>>c>>x>>y) 
    data[x][y]=1; 
} 
n=rows; 
m=cols; 
memset(match1,-1,sizeof(match1)); 
memset(match2,-1,sizeof(match2)); 
fi(rows) 
{ 
  memset(got,0,sizeof(got)); 
  if (bmatch(i)) ans++; 
} 
return ans;     
}}; 
