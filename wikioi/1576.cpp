#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
		using namespace std;
int main(){

	int n;
	scanf("%d",&n);
	int nums[n+1];
	for(int i =1 ;i<=n;i++)
		scanf("%d",&nums[i]);
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[1] =1;
	int max1= 1;
	for(int i = 2 ;i <=n;i++){
		dp[i] = 1;
		for(int j = 1;j<i;j++)
		{
			if(nums[i]>=nums[j])
				dp[i] = max(dp[i],dp[j]+1);
		}
		max1 = max(max1,dp[i]);
	}
	printf("%d\n",max1);
}