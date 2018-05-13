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
        
        t_sum =0
        min_x =0
        min_sum =3
        max_sum =0
        while(min_sum <=2*self.n):
            dp_table = np.zeros((self.n, self.n), dtype=bool)
            sum_table =np.zeros((self.n, self.n))
            for j in range(self.k): 
                x =0
                y =0
                
                x =min_sum/2
                y =min_sum -x
                while(x ==y):
                    x =x-1
                    y =y+1
                    if(x <=min_x):
                        break
                    dp_table[x][y] =True
                    sum_table[x][y] =min_sum
                  
                    min_x =y
                if(j ==self.k)
                    break
                else
                    min_sum =min_sum +self.c
                    
            for i in range(self.n):
                for j in range(self.n):
                    if(dp_table[i][j]):
                        min_sum =sum_table[i][j]
                        t_sum =t_sum+min_sum

            if(t_sum >max_sum):
                max_sum =t_sum

            min_x =0
            min_sum =min_sum+1
                        
        return max_sum

if __name__ == '__main__':
    sp =greedy_approach()
    dp =dp_approach(5,4,2)
    dp.dy_pair_up()

    # result =sp.recur_max_pair_up(12, 7, 3, None)
    

