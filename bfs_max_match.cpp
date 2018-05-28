#include <algorithm>  
#include <functional>  
#include <numeric>  
#include <utility>  
#include <iostream>  
#include <sstream>  
#include <iomanip>  
  
#include <bitset>  
#include <string>  
#include <vector>  
#include <stack>  
#include <deque>  
#include <queue>  
#include <set>  
#include <map>  
  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>  
#include <ctime>  
#include <climits>  
using namespace std;  
   
bool cut[605][605];
int cap[605][605]; 
int from[605];      
bool v[605];         
const int INF = 1000000;  
class RookAttack {  
public:  
    int rows, cols;  
  
 
    int bfs()  
    {         
        memset(v, 0, sizeof(v));  
        memset(from, -1, sizeof(from));  
        queue <int> Q;  
        int start = rows, end = rows + cols + 1;    
        Q.push(start);  
        v[start] = true;  
        int where;  
 
        bool ok = false;  
        while (!Q.empty()) {  
            where = Q.front();  
            Q.pop();  
            for (int i = 0; i <= rows + cols + 1; i++) {  
                if (cap[where][i] > 0 && !v[i]) {     
                    from[i] = where;  
                    v[i] = true;  
                    if (i == end) {  
                        ok = true;  
                        break;  
                    }  
                    Q.push(i);  
                }  
            }  
            if (ok) {  
                break;  
            }  
        }  
 
        int path_cap = INF;  
        where = end;  
        while (from[where] != -1) {  
            int pre = from[where];  
            path_cap = min(path_cap, cap[pre][where]);  
            where = pre;  
        }  
 
        where = end;  
        while (from[where] != -1) {  
            int pre = from[where];  
            cap[pre][where] -= path_cap;  
            cap[where][pre] += path_cap;  
            where = pre;  
        }  
          
        return (path_cap == INF ? 0 : path_cap);  
    }  
  
    int howMany(int rows, int cols, vector <string> cutouts) {  
        int res = 0;  
        this->rows = rows;  
        this->cols = cols;  
        memset(cut, 0, sizeof(cut));  
 
        string S;  
        for (int i = 0; i < cutouts.size(); i++) {  
            S += cutouts[i] + ", ";  
        }             
        for (int i = 0; i < S.size(); i++) {  
            if (',' == S[i]) {  
                S[i] = ' ';  
            }  
        }  
        int r, c;  
        stringstream ss(S);  
  
        while (ss >> r >> c) {  
            cut[r][c + rows + 1] = true;  
        }  
  
        memset(cap, 0, sizeof(cap));  
        for (int i = 0; i < rows; i++) {  
            for (int j = rows + 1; j < rows + cols + 1; j++) {  
                if (!cut[i][j]) {  
                    cap[i][j] = 1;     
                }  
                cap[j][rows + cols + 1] = 1;  
            }  
            cap[rows][i] = 1;   
        }  
        int add;  
        while ( (add = bfs()) != 0 ) {  
            res += add;  
        }  
        return res;  
    }  
};  

typedef int (RookAttack::*METHOD)(int, int, vector<string>);

int main(){
    int row =8;
    int col =8;
    vector<string> cuts= {};
    RookAttack* obj =new RookAttack;
    METHOD Action =&RookAttack::howMany;
    int res =(obj->*Action)(row, col, cuts);
    printf("\n%i\n\n", res);
    delete obj;
    return 0;
}