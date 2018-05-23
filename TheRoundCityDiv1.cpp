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

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN =1000100;

class TheRoundCityDiv1 {
	public:
		// the function might not be needed
    	int bit_cont(unsigned int x){
    		int count;
    		for(count =0; x !=0; count++, x &=x-1);
    		//printf("%i\n", count);
    		return count;
    	}
    	long long find(int); 
};

int np[MAXN];

ll gres(int x, int y){
	vector<int> v;
	while (x>1){
		int p =np[x];
		v.push_back(p);
		while(x%p ==0)
			x /=p;
	}

	int ans =0;
	int nv =v.size();
	for (int i =0; i <(i << nv); i++)
	{
		int np =1, cv =1;
		for(int j =0; j<nv; j++){
			if(i & (1 <<j))
			{
				cv =-cv;
				np =np*v[j];
			}
		
		}
		ans +=cv*(y/np);
	}
	return ans;
}

ll TheRoundCityDiv1::find(int r){
	for (int i =0; i<MAXN; i++)
		np[i] =-1;

	for (int i =2; i<MAXN; i++)
	{
		if(np[i] ==-1)
		{
			for(int j =i; j<MAXN; j+=i)
			{
				if(np[j] ==-1)
					np[j] =i;
			}
		}
	}
	ll ans =4;
	ll ny =r;
	for (int i =1; i <=r; i++)
	{
		ll nhi =r*(ll)r -i*(ll)i;
		while(ny*ny>nhi)
			ny--;
		ans +=4*gres(i, ny);
	}
	return ans;
}

typedef ll (TheRoundCityDiv1::*METHOD)(int);
int main(){
	
	TheRoundCityDiv1* obj =new TheRoundCityDiv1;
	METHOD Action =&TheRoundCityDiv1::find;
	int res =(obj->*Action)(47);
	printf("%i\n\n", res);
	delete obj;
	
	

	return 0;
}




