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
        self.dp_table = np.zeros((k+1, n+1, 2*self.n+1), dtype=bool)
        self.prev =np.zeros((k+1, n+1, 2*self.n+1))

    def trace(c, inx, j, is_):
        ans =np.zeros((inx*2));
        while(inx >= 1):
            r =is_+(inx -1)*c -j
            ans[inx*2 -2] =r
            ans[inx*2 -1] =j
            w =self.prev[inx][j][is_]
            inx =inx -1;
            j =w
        print(ans)
        return ans
    
    def dy_pair_up(self):
        inx =0
        #ans =np.zeros((self.n*2));
        #if(self.k >=self.n/2):
        #    print('I was here')
        #    return ans
        for i in range(self.k+1):
            for j in range(self.n):
                for is_ in range(2*self.n):
                    self.dp_table[i][j][is_] =False
        # solve
        for i in range(self.k):

            j =2
            for j in range(self.n):
                for is_ in range(2*self.n):
                    x =is_+(i-1)*self.c-j;
                    if(x >=j):
                        print('I was here',x,j, is_)
                        break
                    if(x <=1):
                        continue;
                    if(i ==1):
                        self.dp_table[i][j][is_] =True
                    else:
                        for w in range(x):
                            if(self.dp_table[i-1][w][is_]):
                                self.dp_table[i][j][is_] =True
                                self.prev[i][j][is_] =w
                                inx =is_
                                print('I waswas here')
                            break

                if(i ==self.k and self.dp_table[i][j][inx]):
                    return trace(self.c, i, j, inx)

if __name__ == '__main__':
    sp =greedy_approach()
    dp =dp_approach(4,4,2)
    dp.dy_pair_up()

    # result =sp.recur_max_pair_up(12, 7, 3, None)
    

