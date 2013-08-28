//数轴上有n条线段，线段的两端都是整数坐标，坐标范围在0~1000000，每条线段有一个价值，请从n条线段中挑出若干条线段，使得这些线段两两不覆盖（端点可以重合）且线段价值之和最大。n<=1000
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef struct Line{
	int s,e,v;
}Line;
bool cmp(Line a,Line b){
	if(a.e == b.e) return a.s<b.s;
	return a.e < b.e;
}
int main(){
	int n;
	scanf("%d",&n);
	Line lines[n+1];
	for(int i = 1;i<=n;i++)
		scanf("%d%d%d",&lines[i].s,&lines[i].e,&lines[i].v);
	sort(lines+1,lines+n+1,cmp);
	int dp[n+1];//dp[i]表示取第i条线段时所获得的最大价值，dp[i] = max(dp[j])+val[i](如果第i条线段的左端点大于等于第j条的右端点)
	memset(dp,0,sizeof(dp));
	dp[1] = lines[1].v;
	int maxN = dp[1];
	for(int i = 2;i<=n;i++){
		dp[i] = lines[i].v;
		for(int j = 1;j<i;j++){
			if(lines[i].s>=lines[j].e)
				dp[i] = max(dp[i],dp[j]+lines[i].v);
		}
		maxN = max(maxN,dp[i]);
	}
	printf("%d\n",maxN);
}