/*
经典题
一个环形的图，顶点是数字，连线上是运算符合，从中间断开，剩下的是一条线，按照连线上的运算符合组合相连的两点，最终得到一个数字，问怎么从中间断开最终能够得到最大的数字。
解题思路
		枚举可以断开的位置，断开后的顶点和连线组成的线图进行DP。这条线图进行最后一步运算前的左右两侧都是最优子结构，这样递推下去，那么相连的两点就是最小的子结构。
		用dp[i][j]表示从第i个位置开始连续j长度的结果。对于相乘运算会出现负负得正，所以DP过程中不仅要保存最大值，还要保存最小值，计算最小值时还要用到最大值，因为一正一负结果是更小的负。dp_max[i][j]保存最大值，dp_min[i][j]表示最小值。
		dp_max[i][j]=max(dp_max[i][k]+dp_max[i+k+1][j-k-1],dp_min[i][k]*dp_min[i+k+1][j-k-1]),k=0,1,…,j;
dp_min的计算与此类似，注意小标正确和考虑到负负得正，负正得负就行。
	另外由于是个环，数组可以开成两倍大小，这样处理起来可以省掉一些取余操作，方便一些。
	最后对所有枚举的断点位置进行遍历，取最大的值和断点位置。
*/
#include <iostream>
using namespace std;
#define max(a,b) (a>b?a:b)
#define min(a,b) (a>b?b:a)
#define inf 100000000
char opt[101];
int dp_max[101][51];
int dp_min[101][51];
int out[50];
int main()
{
	int N,i,j,k,temp,m,max=-inf;
	char x;
	cin>>N;
	for(i=1;i<=N;i++){
		cin>>opt[i];
		opt[i+N]=opt[i];//形成环形
		cin>>dp_min[i][0];
		dp_max[i][0]=dp_max[i+N][0]=dp_min[i+N][0]=dp_min[i][0];
	}
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++)
		{
			dp_max[i][j]=-inf;
			dp_min[i][j]=inf;
		}
	}
	//dp[i][j]：以某点k(k<j)进行枚举
	for(j=1;j<=N-1;j++)
	{
		for(i=1;i<=N;i++)
		{
			for(k=0;k<j;k++)
			{
				temp=opt[i+k+1]=='t'?dp_min[i][k]+dp_min[i+k+1][j-k-1]:
				min(dp_min[i][k]*dp_min[i+k+1][j-k-1],
				min(dp_min[i][k]*dp_max[i+k+1][j-k-1],dp_max[i][k]*dp_min[i+k+1][j-k-1])
					);
				dp_min[i][j]=min(dp_min[i][j],temp);
				temp=opt[i+k+1]=='t'?dp_max[i][k]+dp_max[i+k+1][j-k-1]:
				max(dp_max[i][k]*dp_max[i+k+1][j-k-1],dp_min[i][k]*dp_min[i+k+1][j-k-1]);
				dp_max[i][j]=max(dp_max[i][j],temp);
			}
			dp_min[i+N][j]=dp_min[i][j];
			dp_max[i+N][j]=dp_max[i][j];
		}
	}
	//可以画图看出，断开某个点，就是取dp[i][N-1]
	for(i=1;i<=N;i++){
		if(dp_max[i][N-1]>max){
			max=dp_max[i][N-1];
			out[0]=i;
			m=1;
		}else if(dp_max[i][N-1]==max){
			out[m++]=i;
		}
	}
	cout<<max<<endl<<out[0];
	for(i=1;i<m;i++)cout<<" "<<out[i];
	cout<<endl;
}
