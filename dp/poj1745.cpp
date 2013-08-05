/*dp：计算每个数字的加减法是否可以得到余数为0的情况。*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#define MAXN 10010
#define MAXK 110
using namespace std;
bool dp[2][MAXK];
int nums[MAXN];
int main(){
	int n,k;
	freopen("1745.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i<=n;i++)
		scanf("%d",&nums[i]);
	memset(dp,false,sizeof(dp));
	for(int i = 0;i<k;i++)
		//需要注意第一个数是否大于0
		if(((nums[1]%k)+k)%k==i)
			dp[1][i]=true;
	 
		
	for(int i = 2;i<=n;i++)
		for(int j = 0 ; j<k;j++)
			dp[i%2][j] = dp[(i-1)%2][((j-nums[i])%k+k)%k]||dp[(i-1)%2][((j+nums[i])%k+k)%k];
	
	if(dp[n%2][0])
		printf("Divisible\n");
	else
		printf("Not divisible\n");
	return 0;
}