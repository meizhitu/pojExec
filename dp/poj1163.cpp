//简单的dp，和poj3176重复。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 400
int dp[MAXN][MAXN];
int nums[MAXN][MAXN];

int main(){
	int n;
	freopen("3176.txt","r",stdin);
	scanf("%d",&n);
	memset(dp,0,sizeof(dp));
	memset(nums,0,sizeof(nums));
	
	for(int i = 1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&nums[i][j]);
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			dp[i][j]=dp[i-1][j]>dp[i-1][j-1]?dp[i-1][j]:dp[i-1][j-1];
			dp[i][j]+=nums[i][j];
		}
	}
	int max = -1;
	for(int i = 1;i<=n;i++)
		if(max < dp[n][i])
			max = dp[n][i];
	printf("%d\n",max);
}