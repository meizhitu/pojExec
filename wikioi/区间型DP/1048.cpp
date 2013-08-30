//区间动态规划，石子归并问题，dp[i][j] =min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]) (i<=k<j)
/*
有n堆石子排成一列，每堆石子有一个重量w[i], 每次合并可以合并相邻的两堆石子，一次合并的代价为两堆石子的重量和w[i]+w[i+1]。问安排怎样的合并顺序，能够使得总合并代价达到最小。
	1 2 3
		3 + 3 =6
			5
			5+1=6 11
*/
#include <iostream>
#include <string.h>
				
#include <stdio.h>
				using namespace std;
				
int main(){
	int n;
	scanf("%d",&n);
	int nums[n+1];
	int sum[n+1];
	int dp[n+1][n+1];
	for(int i =0;i<=n;i++)
		for(int j = 0 ;j<=n;j++){
			if(i==j) dp[i][i]=0;
			else
				dp[i][j] = 100000000;
		}
	sum[0] = 0 ;
	for(int i =1 ;i<=n;i++){
		scanf("%d",&nums[i]);
		sum[i] = sum[i-1]+nums[i];
	}
	dp[0][0] = 0 ;
	for(int len = 2;len<=n;len++)
		for(int i= 1;i+len-1<=n;i++){
			int j = i+len-1;
			for(int k = i;k<j;k++){
				dp[i][j] =min (dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1],dp[i][j]);
			}
		}
		printf("%d\n",dp[1][n]);
}
