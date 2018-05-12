# topcoder stablepairsdiv1
import numpy as np

class greedy_approach:
    def get(self,n,s):
        d = n+n-1-s

        if(d%2 ==0):
            return [n-1-d/2 ,n-d/2]
        else:
            return [s -n, n]
 
    def recur_max_pair_up(self,n,c,k,s=None):
        if (n ==1):
            return []
        if s is None: 
            s = n+n-1
        else:
            g = self.get(n,s)
        g = self.get(n,s)
        return g if k == 1 else self.recur_max_pair_up(g[0]-1,c,k-1,sum(g)-c)+g

class dp_approach:
    def __init__(n, c, k):
        self.n =n
        self.c =c
        self.k =k 
        self.dp = np.zeros((k,n,2*n), dtype=bool)
        self.prev =np.zeros((k, n, 2*n))

    def init(c, inx, y, is_):
        ans =np.zeros((inx*2));
        while(inx >= 1):
            x =is_+(inx -1)*c -y
            ans[inx*2 -2] =x
            ans[inx*2 -1] =y
            int w =prev[inx][y][is_]
            inx =inx -1;
            y =w
        return ans
    
    def dy_pair_up(is_):
        ans =np.zeros((i*2));
        dp = np.zeros((k+1,n,2*n), dtype=bool)
        prev = np.zeros((k+1,n,2*n))

        for i in range(k):
            dp[i] =np.zeros((n+1, 2*n), dtype=bool)
            prev[i] =np.zeros((n+1, 2*n))
            for is_ in range(2*n):
                self.dp[i][y][is_] =False
        
        for i in range(k):
            for j =2 in range(self.n):
                y =y-1
                x =is_+(i-1)*self.c-y;
                if(x >=y):
                    break
                if(x <=1):
                    continue;
                if(i ==1):
                    self.dp[i][y][is_] =True
                else:
                    for w in range(x):
                        if(self.dp[i-1][w][is_]):
                            self.dp[i][y][is_] =True
                            self.prev[i][y][is_] =w
                            break

                if(i ==k && self.dp[i][y][is_]):
                    return init(self.c, i, y, is_)

if __name__ == '__main__':
    sp =greedy_approach()
    result =sp.recur_max_pair_up(12, 7, 3, None)
    print(result)

