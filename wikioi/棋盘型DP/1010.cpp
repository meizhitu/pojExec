/*
　如图，A 点有一个过河卒，需要走到目标 B 点。卒行走规则：可以向下、或者向右。同时在棋盘上的任一点有一个对方的马（如上图的C点），该马所在的点和所有跳跃一步可达的点称为对方马的控制点。例如上图 C 点上的马可以控制 9 个点（图中的P1，P2 … P8 和 C）。卒不能通过对方马的控制点。

　　棋盘用坐标表示，A 点（0，0）、B 点（n,m）(n,m 为不超过 20 的整数，并由键盘输入)，同样马的位置坐标是需要给出的（约定: C不等于A，同时C不等于B）。现在要求你计算出卒从 A 点能够到达 B 点的路径的条数。
1<=n,m<=15
	dp[i][j]表示到达(i,j)的路径数。
	dp[i][j] = dp[i-1][j]+dp[i][j-1] 如果(i,j不在控制点范围内)
		       0 （如果i，j在控制点范围内）
*/
#include <iostream>
#include <stdlib.h>
int main(){
    int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	int dp[n+1][m+1];
	int ava[n+1][m+1];
	memset(dp,0,sizeof(dp));
	memset(ava,true,sizeof(ava));
	if(x+1<=n&&y-2>=0)
		ava[x+1][y-2] = false;
	if(x+1<=n&&y+2<=m)
		ava[x+1][y+2] = false;
	if(x+2<=n&&y-1>=0)
		ava[x+2][y-1] = false;
	if(x+2<=n&&y+1<=m)
		ava[x+2][y+1] = false;
	if(x-2>=0&&y+1<=m)
		ava[x-2][y+1] = false;
	if(x-2>=0&&y-1>=0)
		ava[x-2][y-1] = false;
	if(x-1>=0 && y-2>=0)
		ava[x-1][y-2] = false;
	if(x-1>=0 && y+2<=m)
		ava[x-1][y+2] = false;
	ava[x][y] = false;	  
	dp[0][0]=1; 
	for(int i = 1;i<=n;i++)
	{
		if(ava[i][0])
			//此处之前写dp[i][0]=1错误！必须是下面这种写法，因为前面的不可达，则当前节点也不可达。
			dp[i][0]=dp[i-1][0]; 
	}
	//printf("he\n");
	for(int j = 1;j<=m;j++)
		if(ava[0][j])
			//此处之前写dp[i][0]=1错误！必须是下面这种写法，因为前面的不可达，则当前节点也不可达。
			dp[0][j] = dp[0][j-1];
	for(int i = 1;i<=n;i++)
		for(int j =1;j<=m;j++)
	{
		if(!ava[i][j])
			dp[i][j] = 0;
		else
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
	}
	printf("%d\n",dp[n][m]);
}