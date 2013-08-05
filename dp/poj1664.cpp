#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 15
/*
假设我们要把ｍ个苹果放到ｎ个盘子里，那么很明显的，放得最少的那个盘子里的苹果数，要么是０，要么非０，如果是０，则问题转化为求m个苹果放到n-1个盘子里的分发，如果非零，那么我们可以从每个盘子中移除一个，那么原问题转化为m-n个苹果放到n个盘子里，当然这里最具有迷惑性的一点就是：为何非0的时候每次每个盘子只一走一个，如果最少的盘子里有两个苹果，会不会出现重复？这个问题我们可以这样想，假设放置最少的盘子中有k个苹果，那么这个状态可以唯一的由连续k次每次从每个盘子中拿走一个苹果而得到，这就是说不会出现重复子状态！所以动态规划方程为：
dp[i][j]=dp[i][j-1]+dp[i-j][j]
	注意i<j的情况，例如2个苹果放入3个盘子中 d[2][3] = d[2][2]
*/
int dp[max][max];
int solve(int m,int n){
	for(int i=1;i<=n;i++){
		dp[0][i] = 1;
	}
	for(int i = 1;i<=m;i++)
		dp[i][1] =1;
	for(int i = 1 ; i<=m;i++){
		for(int j = 1; j <=n;j++){
			int k = j;
			if(k>i) k = i;
			dp[i][j] = dp[i-k][k]+dp[i][k-1];
			//printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
		}
	}
	return dp[m][n];
}
int main(){
	int c;
	freopen("1664.txt","r",stdin);
	scanf("%d",&c);
	for(int i=0;i<c;i++)
	{
		int m,n;
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&m,&n);
		printf("%d\n",solve(m,n));
	}

}