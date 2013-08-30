/*

某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
	最长不增子序列和最长不降子序列

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
		using namespace std;
int main(){
	int x;
	int nums[25];
	int i = 1 ;
	while(scanf("%d",&x)!=EOF){
		nums[i++] = x;
	}
	int len = i;
	int dp[len];//最长不增子序列
	int dp1[len];////最长不降子序列
	memset(dp,0,sizeof(dp));
	memset(dp1,0,sizeof(dp1));
	dp1[1] = 1;
	dp[1] =1;
	int max1 = 1;
	int max2 = 1;
	for(int i = 2 ;i < len;i++){
		dp[i] = 1;
		for(int j = 1;j<i;j++)
		{
			if(nums[i]>=nums[j])
				dp[i] = max(dp[i],dp[j]+1);
		}
		max1 = max(max1,dp[i]);
	}
	
	for(int i = 2 ;i < len;i++){
		dp1[i] = 1;
		for(int j = 1;j<i;j++)
		{
			if(nums[i]<=nums[j])
				dp1[i] = max(dp1[i],dp1[j]+1);
		}
		max2 = max(max2,dp1[i]);
		
	}
	printf("%d\n",max1);
	printf("%d\n",max2);
		
}
		