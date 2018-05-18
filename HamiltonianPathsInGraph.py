
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
class HamiltonianPathsInGraph:
	# this is brute force
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
	def ham_dp(self, s):

	def findPath(self, X):
		self.X =X
		return self.ham_bf(set(range(len(X))))

if __name__ == '__main__':
	x =[['.','+'],
		['-','.']]
	ham =HamiltonianPathsInGraph()
	Path =ham.findPath(x)
	print(Path)


