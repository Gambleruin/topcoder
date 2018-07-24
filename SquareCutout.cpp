#include<string.h>

#include <iostream>
#include <fstream>





#include <iostream> 
#include <sstream> 
#include <fstream> 
#include <string> 
#include <vector> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <bitset> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstdio> 

using namespace std; 

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++) 
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++) 

#define INF (1<<29) 

vector<string> readFileToVector(const string& filename)
{
    ifstream source;
    source.open(filename);
    vector<string> lines;
    string line;
    while (getline(source, line))
    {
        lines.push_back(line);
    }
    return lines;
}

/*
void displayVector(const vector<string&> v)
{
    for (int i(0); i != v.size(); ++i)
        cout << "\n" << v[i];
}
*/  
void displayVector(const vector<string> v)
{
    for (int i(0); i != v.size(); ++i)
        cout << "\n" << v[i];
    cout << "\n the solution is: ";
}

class SquareCutout{ 
  public: 

  int verify(vector <string> cutout){ 
    int i,j; 
     
    int X = cutout.size(); 
    int Y = cutout[0].length(); 
     
    int minx = INF, miny = INF, maxx = -INF, maxy = -INF; 
    int cnt = 0; 
     
    REP(i,X) REP(j,Y) if(cutout[i][j] == '#'){ 
      cnt++; 
      minx = min(minx, i); 
      miny = min(miny, j); 
      maxx = max(maxx, i); 
      maxy = max(maxy, j); 
    } 
     
    if(cnt == 0) return 1; 
     
    if(cnt != (maxx - minx + 1) * (maxy - miny + 1)) return 0; 
     
    int dx = maxx - minx + 1; 
    int dy = maxy - miny + 1; 
    int d = max(dx, dy); 
     
    if(dx < d && minx > 0 && maxx < X - 1) return 0; 
    if(dy < d && miny > 0 && maxy < Y - 1) return 0; 
     
    return d; 
  } 

};

int main(int argc, char* argv[]){

    if(argc != 2){
        cerr << "Usage: "<< argv[0]
            << "input.txt" <<endl;
        return 1;
    }

    string f(argv[1]);
    vector<string> cutoff = readFileToVector(f);
    
    // display the input
    displayVector(cutoff);

    // create class object
    SquareCutout sc;
    cout <<sc.verify(cutoff)<<"\n";




    return 0;

}