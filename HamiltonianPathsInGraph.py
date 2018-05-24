
'''
SRM 733 
(this is only for programming practise as all implementations are adapted )
HamiltonianPathsInGraph

difficulty level: hard

In the mathematical field of graph theory, a
 Hamiltonian path (or traceable path) is a 
 path in an undirected or directed graph that visits each vertex exactly once.

 * every tournament contains at least one Hamiltonian path *
 * http://www.math.toronto.edu/gscott/sept20_2016.pdf *	
 * http://codeforces.com/blog/entry/43256?mobile=true&locale=en*
'''


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
		return self.brute_force(s1) +[v] +self.brute_force(s2)

	# using induction but without recursion
	# resources from:
	# https://www.topcoder.com/blog/single-round-match-733-editorials/
	'''
		To implement this, we can follow the steps in our induction 
		above. There are n times where we add nodes, and each of 
		those steps takes O(n) time (O(n) to classify the previous 
		nodes as red or blue, and O(n) time to insert our new node 
		into this list).

		The implementation is almost identical to which the recursion above was constructed except
		this is not recursion, thus it is slightly better than brute force approach 
	'''
	def convert_to_integer(self, size):
		arr =np.zeros((size)) 
		return arr.astype(int)
	def inductive_approach(self, n):
		start =0
		
		end =0
		left =self.convert_to_integer(128) 
		right =self.convert_to_integer(128) 
		ans =self.convert_to_integer(n) 
		'''
		if len(n) ==0:
			return []
		'''

		for i in range(n):
			if self.adj[i][start] =='+':
				left[start] =int(i)
				right[i] =start
				left[i] =-1
				start =i
				continue

			if self.adj[end][i] =='+':
				right[end] =int(i)
				left[i] =end
				right[i] =-1
				end =i
				continue

			j =start
			while self.adj[j][i] == '+':
				j =right[j]
			k =left[j]
			right[k] =i
			left[i] =k
			# ..
			left[j] =i
			right[i] =j

		# getting the final solution
		x =start
		idx =0
		# index off by one error
		while x !=-1 and idx <=n-1:
			print(x)
			ans[idx] =x
			idx+=1
			x =right[x]

		return ans
	'''

		the author of this blog claimed such a hamilton path must exist, 
		however, it is not true for all graphs, if a graph does not have a
		hamilton path, the algorithms above would instantly fail, thus we 
		can instead use dynamic programming
	'''
	# resources from:
	# https://www.hackerearth.com/practice/algorithms/graphs/hamiltonian-path/tutorial/
	# https://www.hackerearth.com/practice/notes/bit-manipulation/
	def check_i_th_bit_is_set(self, i, j):
		if i&(1<<j) :
			return True
		else:
			return False

	def check_subset_path(self, i, j):
		if i^(1<<j):
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

		for i in range(n):
			if self.dp[i][(1<<n) -1]:
				return True
		return False

	def brute_force_findPath(self, X):
		self.X =X
		return self.brute_force(set(range(len(X))))

	def dynamic_programming_findPath(self):
		return self.dp_solve(self.n)

	def inductive_approach_findPath(self):
		return self.inductive_approach(self.n)

if __name__ == '__main__':
	x =[['.','-','-','+'],
		['+','.','+','-'],
		['+','-','.','-'],
		['-','+','+','.']]
	'''
	this is for dynamic programming testing
	adj =[[0, 1],
			[1, 0]]
	'''

	'''
	3
	1
	2
	0
	[3 1 2 0]
	'''
	# currently running the phrase for inductive approach, but the other
	# two were well tested
	ham =HamiltonianPathsInGraph(x, 4)
	Path =ham.inductive_approach_findPath()
	print(Path)
	# Path_Existence =ham.dynamic_programming_findPath()

	


