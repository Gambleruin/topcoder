/*
TCCC 2006, Round 1B Medium

For each city, keep a bit-set of the neighbouring cities. 
Once the part-building factories have been chosen (recursively), 
ANDing together these bit-sets will give a bit-set which describes 
the possible locations of the part-assembly factories. If this 
bit-set has k bits, then there are kCm ways to allocate the part-assembly 
factories.

problem name:
FactoryCounting

problem statement:
http://community.topcoder.com/stat?c=problem_statement&pm=6725&rd=10100

problem difficulty:
medium

implementation sources:
https://community.topcoder.com/tc?module=Static&d1=match_editorials&d2=tccc06_online_rd_1b

*/
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <set>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <queue>
#include <complex>
 
using namespace std;
 
typedef pair<int, int> pii;
typedef long long ll;
 
template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    T tmp;
 
    out.clear();
    while (in >> tmp) out.push_back(tmp);
}
 
class FactoryCounting
{
public:
    long long count(int n, int m, vector <string> county);
};
 
static int edge[32];
static ll choosen[32];
static int K;
 
static ll choose(int p, int q)
{
    ll ans = 1LL;
    if (p < q) return 0LL;
    for (int i = 1; i <= q; i++)
        ans = ans * (p + 1 - i) / i;
    return ans;
}
 
static ll recurse(int a, int b, int start, int m)
{
    if (m == 0)
    {
        int bits = __builtin_popcount(a & ~b);
        return choosen[bits];
    }
    else
    {
        ll ans = 0LL;
        for (int j = start; j + m <= K; j++)
            ans += recurse(a & edge[j], b | (1 << j), j + 1, m - 1);
        return ans;
    }
}
 
long long FactoryCounting::count(int n, int m, vector <string> county)
{
    K = county.size();
    memset(edge, 0, sizeof(edge));
    for (int i = 0; i < K; i++)
        for (int j = 0; j < K; j++)
            if (county[i][j] == 'Y')
                edge[i] |= 1 << j;
 
    for (int i = 0; i <= K; i++)
        choosen[i] = choose(i, n);
 
    return recurse((1 << K) - 1, 0, 0, m);
}

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

int main(int argc, char* argv[]){

    if(argc != 2){
        cerr << "error! Usage: "<< argv[0]
            << "input.txt" <<endl;
        return 1;
    }

    string f(argv[1]);
    vector<string> county = readFileToVector(f);
    

    // create class object
    FactoryCounting fc;
    cout <<fc.count(2, 1, county)<<"\n";

    return 0;

}





