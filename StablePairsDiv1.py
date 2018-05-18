# topcoder stablepairsdiv1
# StablePairsDiv1 [2018 TCO Algorithm Round 1B Med]
import numpy as np

class greedy_approach:
    def get(self,n,s):
        d = n+n-1-s

        if(d%2 ==0):
            return [n-1-d/2 ,n-d/2]
        else:
            return [s -n, n]
 
    def recur_max_pair_up(self, n,c,k,s=None):
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
        
    def solve(self):
        if(self.n ==1):
            return 0

        t_sum =0
        min_x =0
        init_sum =3
        min_sum =3
        max_sum =0
        while(init_sum <=2*self.n):
            # the data structure can be improved if hash table is using as
            # the numpy array merely acts as a look up table, thus not strictly a
            # dynamic appoarch 
            pair_table = np.zeros((self.n+1, self.n+1))
            sum_table =np.zeros((self.n+1, self.n+1))
            min_sum =init_sum
            
            j =1
            while j <=self.k:
                x =0
                y =0
                
                x =min_sum/2
                x =int(x)
                y =min_sum -x
                y =int(y)
                while(x ==y):
                    x-=1
                    y+=1
                if(x <=min_x):
                    break
                print(x, y)
                pair_table[x][y] =1
                sum_table[x][y] =min_sum
                  
                min_x =y
                
                if(j ==self.k):
                    print('I was truly here')
                    break
                else:
                    min_sum =min_sum +self.c
                j +=1

            for i in range(self.n+1):
                for j in range(self.n+1):
                    if(pair_table[i][j]):
                        # print(i, j)
                        val =sum_table[i][j]
                        t_sum =t_sum+val
                        
            if(t_sum >max_sum):
                max_sum =t_sum

            print(max_sum, min_sum)
            if(min_sum >=2*self.n-1):
                break
            
            min_x =0
            t_sum =0
            init_sum =init_sum+1                        
        return max_sum

if __name__ == '__main__':
    sp =greedy_approach()
    dp =dp_approach(10,6,3)
    re =dp.solve()
    print(re)
    # result =sp.recur_max_pair_up(12, 7, 3, None)
    # print(result)
    

