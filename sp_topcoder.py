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
        self.sum_table =np.zeros((k, n, 2*self.n))
        t_sum =0
        min_sum =0
        max_sum =0
        for i in range(2*self.n):
            max_sum =max_sum +min_sum
            if(min_sum<3):
                min_sum =2*i+1
            for j in range(self.k): 
                x =0
                y =0
                if (min_sum <=2*self.n):
                    x =min_sum/2
                    y =min_sum -x
                    while(x ==y):
                        x =x-1
                        y =y+1
                    dp_table[x][y] =True
                    t_sum =t_sum+min_sum

                if(dp_table[x][y]):
                    sum_table[i][j] =min_sum
                elif(t_sum >max_sum and j ==self.k):
                    max_sum =t_sum
                    break

            min_sum =min_sum +self.c


        while(init_s+1 <=2*self.n) : 
            init_s =init_s+1
            p_sum =init_s
            for i in range(self.k): 
                for s in range(p_sum, 2*self.n):     
                    x =p_sum/2
                    y =p_sum -x
                    while(x ==y):
                        x =x-1
                        y =y+1
                self.dp_table[i][s] =True
                self.sum_table[x][y] =p_sum
                p_sum =s+self.c
                



        if(dp_table[i][s])
            max_sum =t_sum
            continue
        if(max_sum <t_sum):
            self.dp_table[i][p_sum] =False



        max_sum =t_sum

        return (self.dp_table, self.sum_table)



if __name__ == '__main__':
    sp =greedy_approach()
    dp =dp_approach(5,4,2)
    dp.dy_pair_up()

    # result =sp.recur_max_pair_up(12, 7, 3, None)
    

