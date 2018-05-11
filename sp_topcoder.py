# topcoder
import numpy as np
class greedy_approach:
    def get(self,n,want):
        d = n+n-1-want

        if(d%2 ==0):
            return [n-1-d/2 ,n-d/2]
        elif(d%2 !=0):
            return [want -n, n]
 
    def recur_max_pair_up(self,n,c,k,wantsum=None):
        if (n ==1):
            return []
        if wantsum is None: 
            wantsum = n+n-1
        else:
            g = self.get(n,wantsum)
        g = self.get(n,wantsum)
        return g if k == 1 else self.recur_max_pair_up(g[0]-1,c,k-1,sum(g)-c)+g

if __name__ == '__main__':
    sp =greedy_approach()
    result =sp.recur_max_pair_up(12, 7, 3, None)
    print(result)

