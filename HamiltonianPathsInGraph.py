
'''
SRM 733
In the mathematical field of graph theory, a
 Hamiltonian path (or traceable path) is a 
 path in an undirected or directed graph that visits each vertex exactly once.

 * every tournament contains at least one Hamiltonian path *
 * http://www.math.toronto.edu/gscott/sept20_2016.pdf *	
 * http://codeforces.com/blog/entry/43256?mobile=true&locale=en*
'''
# HamiltonianPathsInGraph

import numpy as np
class HamiltonianPathsInGraph():
	def __init__(self, adj, MAXN):
		self.dp =np.zeros((MAXN, 1<<MAXN))
		self.adj =adj
		self.n =MAXN
	# brute force
	# sources from:
	# https://community.topcoder.com/stat?c=problem_solution&rd=17140&rm=&cr=40741634&pm=14881
	def brute_force(self, s):
		if len(s) ==0:
			return []
		v =s.pop()
		s1 =set()
		s2 =set()
		for w in s:
			if self.X[v][w] == '-':
				s1.add(w)
			elif self.X[v][w] == '+':
				s2.add(w)
		return self.ham_bf(s1) +[v] +self.ham_bf(s2)

	# using induction but without recursion
	# resources from:
	# https://www.topcoder.com/blog/single-round-match-733-editorials/
	'''
		To implement this, we can follow the steps in our induction 
		above. There are n times where we add nodes, and each of 
		those steps takes O(n) time (O(n) to classify the previous 
		nodes as red or blue, and O(n) time to insert our new node 
		into this list).
	'''
	def inductive_approach(self, n):
		start =0
		end =0
		left =np.zero((128)) 
		right =np.zero((128))
		solution =np.zero((n))
		if len(s) ==0:
			return []
		for i in range(n):
			if self.X[i][start] =='+':



	# this is using dynamic programming
	# resources from:
	# https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/
	# https://www.hackerearth.com/practice/notes/bit-manipulation/
	def check_i_th_bit_is_set(self, i, j):
		if(i&(1<<j) ):
			return True
		else:
			return False

	def check_subset_path(self, i, j):
		if(i^(1<<j)):
			return True
		else:
			return False

	# dynamic programming
	def dp_solve(self, n):
		for i in range(n):
			self.dp[i][1<<i] =True

		for i in range(1<<n):
			for j in range(n):
				if(self.check_i_th_bit_is_set(i, j)):
					for k in range(n):
						bit_set =int(self.check_i_th_bit_is_set(i, k))
						path_set =int(self.check_subset_path(i, j))
						if((bit_set and self.adj[k][j]) and (k!=j 
							and self.dp[k][path_set]) ):
							self.dp[j][i] =True
							break

		print(self.dp)
		for i in range(n):
			if (self.dp[i][(1<<n) -1]):
				return True
		return False

	def brute_force_findPath(self, X):
		self.X =X
		return self.brute_force(set(range(len(X))))

	def dynamic_programming_findPath(self):
		return self.dp_solve(self.n)

	def inductive_approach_findPath(self, X):




if __name__ == '__main__':
	x =[['.','+'],
		['-','.']]
	adj =[[0, 1],
			[1, 0]]

	ham =HamiltonianPathsInGraph(adj, 2)
	Path_Existence =ham.dynamic_programming_findPath()
	
	# print(Path_Existence)


