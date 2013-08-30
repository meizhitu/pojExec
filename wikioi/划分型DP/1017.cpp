/*
今年是国际数学联盟确定的“2000——世界数学年”，又恰逢我国著名数学家华罗庚先生诞辰90周年。在华罗庚先生的家乡江苏金坛，组织了一场别开生面的数学智力竞赛的活动，你的一个好朋友XZ也有幸得以参加。活动中，主持人给所有参加活动的选手出了这样一道题目：
 
设有一个长度为N的数字串，要求选手使用K个乘号将它分成K+1个部分，找出一种分法，使得这K+1个部分的乘积能够为最大。
 
同时，为了帮助选手能够正确理解题意，主持人还举了如下的一个例子：
 
有一个数字串：312， 当N=3，K=1时会有以下两种分法：
 
1)  3*12=36
2)  31*2=62
  
   这时，符合题目要求的结果是：31*2=62
 
   现在，请你帮助你的好朋友XZ设计一个程序，求得正确的答案。
	   dp[i][k]表示从0到i个数中含有k个乘号所得到最大值。
	   num[i][j]由i到j所组成的数字
	   dp[i][k] =max(dp[l][k-1]*num[l][i]);
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int toNum(int s,int e,char chars[]){
	int ret = 0;
	for(int i = s-1;i<e;i++)
		ret = 10*ret + (chars[i]-'0');
	return ret;
}
int main(){
	int n,k;
	cin>>n>>k;
	char chars[1000000];
	cin>>chars;
	
	int dp[n+1][k+1];
	for(int i = 0;i<=n;i++)
		for(int j = 0;j<=k;j++)
			dp[i][j] = 0;
	for(int i = 1;i<=n;i++)
		dp[i][0]=toNum(1,i,chars);
	//dp[1][0] = chars[1]-'0';
	//printf("%d\n",dp[1][0]);
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=k;j++)
	{
		for(int l = 1;l<i;l++){
			dp[i][j] = max(dp[i][j],dp[l][j-1]*toNum(l+1,i,chars));
		
		}
	}
	printf("%d\n",dp[n][k]);
	return 0;
}