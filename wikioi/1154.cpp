//区间动态规划 dp[i][j]表示头标记为i，尾标记为j的珠子能释放的最大能量。dp[i][j] =max(dp[i][j],dp[i][k]+dp[k+1][j]+a[i]*a[k]*a[j])
//2 3 5 10
//(23 35)(510 102)
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef struct Node{
	int s,e;
}Node;

int main(){
	int n ;
	scanf("%d",&n);
	Node nodes[n+1];
	int nums[2*n+1];
	for(int i =1 ;i<=n;i+=1)
	{
		scanf("%d",&nums[i]);
	}
	for(int i = n+1;i<=2*n;i++)
		nums[i] = nums[i-n];
	int k = 1;
	int dp[2*n+1][2*n+1];
	memset(dp,0,sizeof(dp));
	for(int len = 2;len<=2*n;len++)
		for(int i = 1;i+len<=2*n;i++){
			int j = i+len;
			for(int k = i+1;k<j;k++)
				//注意次数的dp[i][k],dp[k][j]表示第i个数到第k个数为一组，第k个数到第j个数为一组。
				dp[i][j] = max(dp[i][j],dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
				 
		}
		int ans = 0;
		for(int i = 1;i<=n;i++) //因为项链的长度最多为n，虽然把环变成了list，也只能统计长度为n的能量。
			ans = max(ans,dp[i][i+n]);
		printf("%d\n",ans);
}