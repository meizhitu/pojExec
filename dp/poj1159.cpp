/*
求变成回文子串需要添加的字符个数。
	经典题目
*/
#include <stdio.h>
#include <string.h>
#define MAXS 5010
int dp[2][MAXS];
char s[MAXS];
char reverse[MAXS];
int main(){
	freopen("1159.txt","r",stdin);
	memset(s,0,sizeof(s));
	memset(reverse,0,sizeof(reverse));
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
	for( i = 1;i<=len;i++)
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
	printf("%d\n",len-dp[(i-1)%2][len]);
	return 0;
}