//斐波那契数列
int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[1] = 1 ;
	dp[0] =1;    
	for(int i = 2; i<=n;i++)
		dp[i] = dp[i-1]+dp[i-2];
	return dp[n];
}