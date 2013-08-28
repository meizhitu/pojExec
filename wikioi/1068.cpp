/*
小明过生日的时候，爸爸送给他一副乌龟棋当作礼物。 乌龟棋的棋盘是一行N个格子，每个格子上一个分数（非负整数）。棋盘第1格是唯一 的起点，第N格是终点，游戏要求玩家控制一个乌龟棋子从起点出发走到终点。
…… 1 2 3 4 5 ……N 乌龟棋中M张爬行卡片，分成4种不同的类型（M张卡片中不一定包含所有4种类型 的卡片，见样例），每种类型的卡片上分别标有1、2、3、4四个数字之一，表示使用这种卡 片后，乌龟棋子将向前爬行相应的格子数。游戏中，玩家每次需要从所有的爬行卡片中选择 一张之前没有使用过的爬行卡片，控制乌龟棋子前进相应的格子数，每张卡片只能使用一次。 游戏中，乌龟棋子自动获得起点格子的分数，并且在后续的爬行中每到达一个格子，就得到 该格子相应的分数。玩家最终游戏得分就是乌龟棋子从起点到终点过程中到过的所有格子的 分数总和。 很明显，用不同的爬行卡片使用顺序会使得最终游戏的得分不同，小明想要找到一种卡 片使用顺序使得最终游戏得分最多。 现在，告诉你棋盘上每个格子的分数和所有的爬行卡片，你能告诉小明，他最多能得到 多少分吗？
	*/
	//dp[i][j][k][l]表示第一张卡用i张，第二张卡用j张，第三种卡用k张，第四章卡用l张所得到的最大分数。
	//dp[i][j][k][l] = score[1+i+2*j+3*k+4*l]+max(dp[i-1][j][k][l],dp[i][j-1][k][l],dp[i][j][k-1][l],dp[i][j][k][l-1]);
#include <iostream>
#include <stdio.h>
#include <string.h>
	
using namespace std;

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int score[n+1];
	int cards[m+1];
	int total[5];
	
	memset(total,0,sizeof(total));
	for(int i = 1;i<=n;i++)
		scanf("%d",&score[i]);
	for(int i =1 ;i<=m;i++){
		scanf("%d",&cards[i]);
		total[cards[i]]++;
	}
	int dp[total[1]+1][total[2]+1][total[3]+1][total[4]+1];
	memset(dp,0,sizeof(dp));
	dp[0][0][0][0] = score[1];
	for(int i = 0;i<=total[1];i++)
		for(int j = 0;j<=total[2];j++)
			for(int k = 0;k<=total[3];k++)
				for(int l =0;l<=total[4];l++)
					{
						if(i==0 && j==0 && k==0 &&l==0) continue;
						dp[i][j][k][l] =score[i+2*j+3*k+4*l+1];
						int maxN = INT_MIN;
						if(i>=1)
							maxN = max(maxN,dp[i-1][j][k][l]);
						if(j>=1)
							maxN = max(maxN,dp[i][j-1][k][l]);
						if(k>=1)
							maxN = max(maxN,dp[i][j][k-1][l]);
						if(l>=1)
							maxN = max(maxN,dp[i][j][k][l-1]);					
						dp[i][j][k][l] += maxN;
					}	
	printf("%d\n",dp[total[1]][total[2]][total[3]][total[4]]);
}