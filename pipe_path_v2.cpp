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
using namespace std;
 
vector< string > tokenize( string a, string b ) {
  const char *q = a.c_str();
  while( count( b.begin(), b.end(), *q ) ) {
    q++;
  }
  vector< string > oot;
  while( *q ) {
    const char *e = q;
    while( *e && !count( b.begin(), b.end(), *e ) ) {
      e++;
    }
    oot.push_back( string( q, e ) );
    q = e;
    while( count( b.begin(), b.end(), *q ) ) {
      q++;
    }
  }
  return oot;
}

int main(){

vector<string> caps_str= {"1,10 2,9","","1,100"};
vector<string> costs_str= {"1,100 2,50","","1,50"};

for( int i = 0; i < incaps.size(); i++ ) {
      vector< string > ica = tokenize( incaps[ i ], " " );
      vector< string > cca = tokenize( incosts[ i ], " " );
      for( int j = 0; j < ica.size(); j++ ) {
        vector< int > icb = sti( tokenize( ica[ j ], "," ) );
        vector< int > ccb = sti( tokenize( cca[ j ], "," ) );
        path foo;
        foo.dest = icb[ 0 ];
        foo.flow = icb[ 1 ];
        foo.cost = ccb[ 1 ];
//        printf( "%d->%d, %d, %d\n", i, foo.dest, foo.flow, foo.cost );
        cc[ i ].push_back( foo );
        cp.insert( foo.flow );
      }
    }
return 0;
}



