#include <iostream>
#include <vector>

using namespace std;
//傻逼了，一个dp

int uniquePaths(int m, int n) {
	int dp[m+1][n+1];
	memset(dp,0,sizeof(dp));
	for(int j =1;j<=n;j++)
		dp[1][j] = 1;
	for(int j =1;j<=m;j++)
		dp[j][1] = 1;
	for(int i = 2;i<=m;i++)
		for(int j =2;j<=n;j++)
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
	return dp[m][n];
}
int main(){
	cout <<uniquePaths(2,2)<<endl;
}