/*
求变成回文子串需要添加的字符个数。
	d[i][j]:表示s1中前i个字符和s2中前j个字符所含有的公共子序列长度
	经典题目
		*/
#include <stdio.h>
#include <string.h>
#include <iostream>
		using namespace std;
#define MAXS 5010
int dp[2][MAXS];
char s[MAXS];
int main(){
	freopen("1159.txt","r",stdin);
	memset(s,0,sizeof(s));
	memset(dp,0,sizeof(dp));
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int len = strlen(s);
	for(int i=0;i<len;i++)
	{
		dp[0][i] = 0 ;
		dp[1][i]=0;
	}
	int i,j ;
	for( i = 1;i<=len;i++){
		for(j=len;j>=0;j--)
		{
			if(s[i-1]==s[j-1])
				dp[i%2][len-j+1] = dp[(i-1)%2][len-j]+1;
			else
			{
				int a1=dp[(i-1)%2][len-j+1];
				int a2=dp[(i)%2][len-j];
				dp[i%2][len-j+1]=a1>a2?a1:a2;
			}
		}
	}
	printf("%d\n",len-dp[(i-1)%2][len]);
	return 0;
}