
'''
SRM 733
In the mathematical field of graph theory, a
 Hamiltonian path (or traceable path) is a 
 path in an undirected or directed graph that visits each vertex exactly once.

 * every tournament contains at least one Hamiltonian path *
 * http://www.math.toronto.edu/gscott/sept20_2016.pdf *	
'''
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

	def findPath(self, X):
		self.X =X
		return self.ham_bf(set(range(len(X))))

if __name__ == '__main__':
	x =[['.','+'],
		['-','.']]
	bf =HamiltonianPathsInGraph()
	Path =bf.findPath(x)
	print(Path)


