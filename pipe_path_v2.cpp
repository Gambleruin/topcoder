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
using namespace std;

void print(vector<string>  str){
  for (auto i = str.begin(); i != str.end(); ++i){
    printf("\n wewanna know what is oot");
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
    print(oot);
    printf("\n\n\n\n\n\n\n\n");
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

int main(){

vector<string> caps_str= {"1,10 2,9","","1,100"};
vector<string> costs_str= {"1,100 2,50","","1,50"};

for( int i = 0; i < caps_str.size(); i++) {
      vector< string > ica = tokenize( caps_str[ i ], " " );
      //break;
      vector< string > cca = tokenize( costs_str[ i ], " " );
      for( int j = 0; j < ica.size(); j++ ) {
        //printf("%lu\n\n\n", ica.size());
        vector< int > icb = sti( tokenize( ica[ j ], "," ) );
        vector< int > ccb = sti( tokenize( cca[ j ], "," ) );
        //printf( "%s, %s, %d, %d,\n", ica[i+1].c_str(), cca[i+1].c_str(), i, j);
      }
      //printf("outter loop ye one turn\n");
}

return 0;
}



