/*
SRM 734
(this is only for programming practise as all implementations are adapted, I do not implement them originally )
TheRoundCityDiv1
The problem statement:
https://community.topcoder.com/stat?c=problem_statement&pm=14897
sources from:
https://community.topcoder.com/stat?c=problem_solution&rd=17158&rm=331262&cr=10574855&pm=14897
original code was in java, the modification of the code is tend to make it more concise and efficient 
difficulty level: easy
*/

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <array>
#include <climits>

using namespace std;

class TheRoundCityDiv1 {
	public:
    	int *divisors = new int[300];

    	int bit_cont(unsigned int x){
    		int count;
    		for(count =0; x !=0; count++, x &=x-1);
    		//printf("%i\n", count);
    		return count;
    	}
 
    	int find(int r) {
        	int res = 0;
        	if (r >= 1) ++res;
        	if (r >= 2) ++res;
        
        	int *d = new int[r + 1];
        
        	for (int i = 2; i <= r; ++i)
            	if (d[i] == 0) {
                	for (int j = i; j <= r; j += i)
                    	if (d[j] == 0) {
                        	d[j] = i;
                    	}
            	}
        int y = r;
        for (int x = 2; x <= r; ++x) {
            while (x * x + y * y > r * (int) r) --y;
            	res += 2 * countUpTo((int) min(x, y), (int) x, d);
            	printf("%i\n\n", res);
        }
        printf("was I here?%i\n\n", res);
        return res * 4;
            
    	}
 	
    	int countUpTo(int max, int relativelyPrimeWith, int d[]) {
        	int nd = 0;
        	int tmp = relativelyPrimeWith;
        	

        	while (tmp > 1) {
        		//printf("was I here?\n\n\n\n");
            	int a = d[tmp];
            	divisors[nd++] = a;
            	while (tmp % a == 0) {
                	tmp /= a;
            	}
        	}
        	int res = 0;
        	for (int mask = 0; mask < (1 << nd); ++mask) {
            	int by = 1;
            	for (int i = 0; i < nd; ++i) if ((mask & (1 << i)) != 0) by *= divisors[i];
            		int got = max / by;
            	if (bit_cont(mask) % 2 == 0) res += got;
            	else res -= got;
        	}
        	return res;
    	}
};

typedef int (TheRoundCityDiv1::*METHOD)(int);

int main(){

	TheRoundCityDiv1* obj =new TheRoundCityDiv1;
	METHOD Action =&TheRoundCityDiv1::find;
	int res =(obj->*Action)(3);
	printf("%i\n\n", res);
	delete obj;
	return 0;
}




