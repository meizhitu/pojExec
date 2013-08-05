/*
求公共子序列长度，递推公式
	if(s1[i-1]==s2[j-1])
		dp[i][j] = dp[i-1][j-1]+1;
	else{
		int max = dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
		dp[i][j]=max;
*/
#include <stdio.h>
#include <string.h>
#define MAXS 1000
char s1[MAXS];
char s2[MAXS];
int dp[MAXS][MAXS];
void init(){
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(dp,0,sizeof(dp));
}
int main(){
	init();
	freopen("1458.txt","r",stdin);
	while(scanf("%s %s",s1,s2)!=EOF){
		int i,j;
		for( i = 0;i<strlen(s1);i++)
			dp[i][0] = 0;
		for( i = 0;i<strlen(s2);i++)
			dp[0][i]=0;
		for( i=1;i<=strlen(s1);i++)
			for( j = 1;j<=strlen(s2);j++)
			{
				if(s1[i-1]==s2[j-1])
					dp[i][j] = dp[i-1][j-1]+1;
				else{
					int max = dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1];
					dp[i][j]=max;
				}
			}
			printf("%d\n",dp[i-1][j-1]);
		init();
	}
	return 0;
}

