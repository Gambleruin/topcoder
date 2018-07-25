class TestProctoring {
	public:
	double expectedTime(vector <int> p, vector <int> q) {
		vector<double> D;
		int N,i;
		N=p.size();
		FOR(i,N) D.push_back(1.0*p[i]/q[i]);
		double ret=0;
		for(int mask=1;mask<1<<N;mask++) {
			double left=1;
			FOR(i,N) if(mask&(1<<i)) left*=(1-D[i]);
			if(__builtin_popcount(mask)%2==0) ret-=1/(1-left);
			else ret+=1/(1-left);
		}
		return ret;
		
	}
}