# topcoder stablepairsdiv1
import numpy as np

class greedy_approach:
    def get(self,n,s):
        d = n+n-1-s

        if(d%2 ==0):
            return [n-1-d/2 ,n-d/2]
        else:
            return [s -n, n]
 
    def recur_max_pair_up(n,c,k,s=None):
        if (n ==1):
            return []
        if s is None: 
            s = n+n-1
        else:
            g = self.get(n,s)
        g = self.get(n,s)
        return g if k == 1 else self.recur_max_pair_up(g[0]-1,c,k-1,sum(g)-c)+g

class dp_approach:
    def __init__(self, n, c, k):
        self.n =n
        self.c =c
        self.k =k 
        self.dp_table = np.zeros((k, n, 2*self.n), dtype=bool)
        self.prev =np.zeros((k, n, 2*self.n))
           
    def dy_pair_up(self):
        for i in range(self.k):
            for j in range(self.n):
                for s in range(2*self.n):
                    self.dp_table[i][j][s] =False
        # solve
        for i in range(self.k):
            for j in range(self.n):
                for s in range(2*self.n):
                    prev_s =self.sum_table[i][j-1][s]
                    if (s >=val+c):
                        x =s/2
                        y =s-x
                        while(x ==y):
                            x =x-1
                            y =y+1
                    else
                        break
                    val =y
                    self.dp_table[i][s] =True
                    self.sum_table[x][y][val] =s
    
    return (self.dp_table, self.sum_table)

if __name__ == '__main__':
    sp =greedy_approach()
    dp =dp_approach(5,4,2)
    dp.dy_pair_up()

    # result =sp.recur_max_pair_up(12, 7, 3, None)
    

