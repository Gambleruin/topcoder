
'''
SRM 733
In the mathematical field of graph theory, a
 Hamiltonian path (or traceable path) is a 
 path in an undirected or directed graph that visits each vertex exactly once.

 * every tournament contains at least one Hamiltonian path *
 * http://www.math.toronto.edu/gscott/sept20_2016.pdf *	
'''
# HamiltonianPathsInGraph
# sources from:
# https://community.topcoder.com/stat?c=problem_solution&rd=17140&rm=&cr=40741634&pm=14881
class HamiltonianPathsInGraph():
	def __init__(self, adj, MAXN):
		self.dp =np.zeros((MAXN, 1<<MAXN))
		self.adj =adj
	# brute force
	def ham_bf(self, s):
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
	# this is using dynamic programming
	# coding resources
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
	def ham_dp(self, s, adj, n):
		for i in range(n):
			self.dp[i][1<<i] =True

		for i in range(1<<n):
			for j in range(n):
				if(check_i_th_bit_is_set(i, j)):
					for k in range(n):
						if(check_i_th_bit_is_set(i, k) and self.adj[k][j] and k!=j and dp[k][check_subset_path(i, j)] ):
							self.dp[j][i] =True
							break

	def solve(self, n):
		for i in range(n):
			if (self.dp[i][(1<<n) -1]):
				return True
		return False

	def brute_force_findPath(self, X):
		self.X =X
		return self.ham_bf(set(range(len(X))))

	def dynamic_programming_findPath(self):
		return solve(n)


if __name__ == '__main__':
	x =[['.','+'],
		['-','.']]
	MAXN =0
	ham =HamiltonianPathsInGraph(x, )
	Path =ham.findPath(x)
	dp_result =ham.dynamic_programming_findPath()
	print(Path)


