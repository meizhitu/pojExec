#include <iostream>
#include <vector>

using namespace std;
//傻逼了，一个dp

int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	int dp[m+1][n+1];
	memset(dp,0,sizeof(dp));
	if(obstacleGrid[0][0]==0) dp[1][1] = 1;
	else return 0;
	for(int i = 2;i<=n;i++)
		if(dp[1][i-1]>0 && obstacleGrid[0][i-1]==0)
			dp[1][i] = 1;
	for(int j = 2;j<=m;j++)
		if(dp[j-1][1] > 0 && obstacleGrid[j-1][0]==0)
			dp[j][1] =1 ;
	for(int i = 2;i<=m;i++)
		for(int j = 2; j<=n;j++)
	{
			if(dp[i][j-1]>0 && obstacleGrid[i-1][j-1]==0)
				dp[i][j]+=dp[i][j-1];
			if(dp[i-1][j]>0 && obstacleGrid[i-1][j-1]==0)
				dp[i][j]+=dp[i-1][j];
			if(obstacleGrid[i-1][j-1]==1)
				dp[i][j] = 0 ;
				
	}
	
	return dp[m][n];
}
int main(){
	vector<vector<int> > obstacleGrid;
	int a[3][3]={{0,0,0},{0,1,0},{0,0,0}};
	for(int i = 0;i<3;i++)
	{
		vector<int>  inn;
		for(int j = 0 ;j<3;j++)
			inn.push_back(a[i][j]);
		obstacleGrid.push_back(inn);
	}
	cout <<uniquePathsWithObstacles(obstacleGrid)<<endl;
}