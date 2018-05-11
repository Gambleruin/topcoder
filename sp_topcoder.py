# topcoder
import numpy as np
class greedy_approach:
    def get(self,n,s):
        d = n+n-1-s

        if(d%2 ==0):
            return [n-1-d/2 ,n-d/2]
        elif(d%2 !=0):
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


if __name__ == '__main__':
    sp =greedy_approach()
    result =sp.recur_max_pair_up(12, 7, 3, None)
    print(result)

