#include <iostream>
#include <vector>
using namespace std;
//Given a m x n grid filled with non-negative numbers, find a path from top left
// to bottom right which minimizes the sum of all numbers along its path.
int minPathSum(vector<vector<int> > &grid) {
	int m = grid.size();
	if(0==m) return 0;
	int n = grid[0].size();
	//cout <<m<<" "<<n<<endl;
	int minV[n+1];
	for(int i = 0;i <=n;i++)
		minV[i] = INT_MAX;
//	memset(minV,INT_MAX,sizeof(minV));
	//	minV[0] = 0;
	minV[1] =0;
	for(int i = 1; i<=m;i++)
		for(int j = 1; j<=n;j++){
			minV[j] = min(minV[j],minV[j-1])+grid[i-1][j-1];
		//	cout <<i<<" j "<<j<<" min "<<minV[j]<<endl;
		}
		
	return minV[n];
}
int main(){
	vector<vector<int> > grid;
	int m[2][2]={{1,2},{1,1}};
	int len = 2;
	//int m[3][3] = {{1,2,3},{1,0,5},{3,4,7}};
	for(int i = 0 ;i<len;i++){
		vector<int> inn;
		for(int j= 0 ;j<len;j++)
			inn.push_back(m[i][j]);
		grid.push_back(inn);
	}
	cout <<minPathSum(grid)<<endl;;
}
