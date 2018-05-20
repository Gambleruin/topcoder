# topcoder
import numpy as np
class StablePairsDiv1:
    def merge(self,a,b):
        return a and a+b
 
    def get(self,n,want):
        d = n+n-1-want
        return [n-1-d/2-d%2,n-d/2]
 
    def findMaxStablePairs(self,n,c,k,wantsum=None):
        if wantsum is None: 
        	wantsum = n+n-1
        if not 
        	1+2 &amp;amp;lt;= wantsum &amp;amp;lt;= n+n-1: return []
 
        g = self.get(n,wantsum)
        return g if k == 1 else self.merge(self.findMaxStablePairs(g[0]-1,c,k-1,sum(g)-c), g)
