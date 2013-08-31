/*
给定N（小于等于8）个点的地图，以及地图上各点的相邻关系，请输出用4种颜色将地图涂色的所有方案数（要求相邻两点不能涂成相同的颜色）
数据中0代表不相邻，1代表相邻
*/
#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX_N = 21;
int N;
int A[MAX_N][MAX_N];
int T[MAX_N];
long long ans=0;
int init()
{
	int i,j;
	scanf("%d",&N);
	memset(T,0,sizeof(T));
	for (i=1;i<=N;i++)
		for (j=1;j<=N;j++)
			scanf("%d",&A[i][j]);
}
int dfs(int t)
{
	if (t>N) {ans++;return 0;}
	int i,j;
	for (i=1;i<=4;i++)
	{
		bool next = true;
		for (j=1;j<=N;j++)
			//判断t相连的节点是否和颜色相同
			if (A[j][t]&&T[j]==i){
				next = false;
			} 
		if (next)
		{
			T[t]=i;//试探，记录节点t所使用的颜色。
			dfs(t+1);
			T[t]=0; //回退
		}
	}
}
int put()
{
	cout<<ans;
}
int main()
{
	init();
	dfs(1);
	put();
	return 0;
}
