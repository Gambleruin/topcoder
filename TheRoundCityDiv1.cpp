/*
SRM 734
(this is only for programming practise )
TheRoundCityDiv1
The problem statement:
https://community.topcoder.com/stat?c=problem_statement&pm=14897
sources from:
https://community.topcoder.com/stat?c=problem_solution&rd=17158&rm=&cr=22907549&pm=14897
difficulty level: easy
*/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
 
using namespace std;
typedef long long ll;
const int MAXN = 100;
 
class TheRoundCityDiv1 {
public:
  long long find(int);
};
 
int np[MAXN];

void Print(int *arr, unsigned size){
	for (int i =0; i<size; i++){
		cout <<arr[i]<<endl;
	}

}
 
ll gres (int x, int y) // # from 1..y that are rel prime to x
{
  vector <int> v;
  printf("%i%i\nwas I here\n",x,y);
  while (x > 1)
  {
    int p = np[x];
    printf("\nthe prime is:%i\n", p);
    v.push_back(p);
    while (x % p == 0)
      x /= p;
    printf("\nafter loop x has been changed to:%i\n", x);
  }
  
  
  int ans = 0;
  int nv = v.size();
  for (int i = 0; i < (1 << nv); i++)
  {
    int np = 1, cv = 1;
    for (int j = 0; j < nv; j++)
      if (i & (1 << j))
      {
        cv = -cv;
        np = np * v[j];
        printf("\nafter multiply by v ,np(int value) has been changed to: and also cv is%i\n%i\n", np, y);
      }
    ans += cv * (y / np);
  }
  printf("\nthe number of coprime\n%i\n\n", ans);
  return ans;
}



 
long long TheRoundCityDiv1::find(int r) {
  // generate all the prime numbers
  for (int i = 0; i < MAXN; i++)
    np[i] = -1;
  
  for (int i = 2; i < MAXN; i++)
  {
    if (np[i] == -1)
    {
      for (int j = i; j < MAXN; j += i)
      {
        if (np[j] == -1)
          np[j] = i;
      }
    }
  }
  //Print(np, MAXN);

  ll ans = 4;
  ll ny = r;
  ll temp =0;
  for (int i = 1; i <= r; i++)
  {
    ll nhi = r * (ll) r - i * (ll) i;
    while (ny * ny > nhi)
      ny--;
    temp =4 * gres (i, ny); 	
    ans += temp;
  }
  return ans;
}

typedef ll (TheRoundCityDiv1::*METHOD)(int);
int main(){
	
	TheRoundCityDiv1* obj =new TheRoundCityDiv1;
	METHOD Action =&TheRoundCityDiv1::find;
	int res =(obj->*Action)(2);
	//printf("%i\n\n", res);
	delete obj;
	return 0;
}




