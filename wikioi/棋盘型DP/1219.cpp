/*
设有一个n*m的棋盘（2≤n≤50，2≤m≤50），如下图，在棋盘上有一个中国象棋马。
规定：
1)马只能走日字
2)马只能向右跳
问给定起点x1,y1和终点x2,y2，求出马从x1,y1出发到x2,y2的合法路径条数。
*/
	//动态规划:dp[i][j] = dp[i-1][j+2]+dp[i-2][j-1]+dp[i-2][j+1],位置(i,j)路径数。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 101
long long dp[MAXN][MAXN];
	
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	
	dp[x1][y1] =1;
	for(int i = x1+1;i<=n;i++)
		//注意此处的j的起点不是y1,而是1，因为从(x1,y1)是可以到达y=1的位置的，所以需要完全遍历y的范围。
		for(int j = 1;j<=m;j++){
			dp[i][j] = dp[i-1][j+2]+dp[i-2][j-1]+dp[i-2][j+1];	
			if(j>=2)
				dp[i][j] +=dp[i-1][j-2];
		}
	printf("%lld\n",dp[x2][y2]);
	return 0;
}
