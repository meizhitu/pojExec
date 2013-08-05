//此题有两种解题，两种不同状态函数的表示。一种f[i][j]表示第i束花插入第[j]个瓶子里面所获得的最大的美观程度。
//则状态转移函数可以表示为f[i][j]=max(f[i-1][k]+a[i][j])其中i-1<=k<j;需要计算F[F][F]到F[F][V]个花瓶的值
//第二种解法的状态函数为f[i][j]表示第i束花插入前j个瓶子里面。则状态转移函数为f[i][j]=max(f[i-1][j-1]+a[i][j],f[i][j-1])
//表示情况1：第i束花放在第j个花瓶里；第i束花不放在第j个花瓶里
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXF 105
int dp[MAXF][MAXF];
int beau[MAXF][MAXF];
int max(int a,int b)
{
	return a>b?a:b;
}
void init(){
	for(int i = 0;i<MAXF;i++)
		for(int j = 0;j<MAXF;j++)
			dp[i][j] = -1000000;
	for(int i = 0;i<MAXF;i++)
		dp[0][i]=0;
}
int main(){
	int f,v;
	freopen("1157.txt","r",stdin);
	while(scanf("%d%d",&f,&v)!=EOF){
		for(int i = 1;i<=f;i++)
			for(int j = 1;j<=v;j++)
				scanf("%d",&beau[i][j]);
		init();
		for(int i = 1;i<=f;i++)
			for(int j = i;j<=v;j++)
				dp[i][j] =max(dp[i-1][j-1]+beau[i][j],dp[i][j-1]);
			
 		
		printf("%d\n",dp[f][v]);
	}
	return 0;
}