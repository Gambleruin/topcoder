/*

TCO 2003 - Semifinal Round 4 Division 1 [topcoder]
problem:
AvoidRoads

problem statement:
https://community.topcoder.com/stat?c=problem_statement&pm=1889&rd=4709
Difficult level: easy

this problem can be solved using dynamic programming 

*/

long ways(int x, int y){
	if(x==0&&y==0)return 1;
	long ret = 0;
	if(!blocked(x-1,y,x,y))ret+=ways(x-1,y);
	if(!blocked(x,y-1,x,y))ret+=ways(x,y-1);
	return ret;
}

long way_with_momerize(int x, int y){
ways[0][0] = 1;
	for(int x = 0; x<=width; x++)
	for(int y = 0; y<=height; y++){
		if(!blocked(x-1,y,x,y))ways[x][y]+=ways[x-1][y];
		if(!blocked(x,y-1,x,y))ways[x][y]+=ways[x][y-1];
	}
	return ways[width][height];
}


