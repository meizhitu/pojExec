#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1010
int dp[MAXN];
int nums[MAXN];
int main(){
	int n ;
	scanf("%d",&n);
	for(int i = 1 ;i<=n;i++)
		scanf("%d",&nums[i]);
	memset(dp,0,sizeof(dp));
	dp[1]=1;
	int max;
	for(int i = 2;i<=n;i++){
		 max = -1;
		for(int j = 1;j<i;j++){
			if(nums[i]>nums[j] && max<dp[j])
				max = dp[j];
		}
		if(max == -1)
			dp[i] = 1;
		else
			dp[i] = max+1;
	}
	max = dp[1];
	for(int i =2;i<=n;i++)
		if(max < dp[i])
			max = dp[i];
	printf("%d\n",max);
}