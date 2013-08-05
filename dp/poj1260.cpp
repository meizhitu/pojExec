/*
令dp[i]表示在已知第i类珍珠时,所需支付的最低价格
则状态方程为：
dp[i]=(a[i]+10)*p[i]+dp[i-1];  //当第i种珍珠出现时，未优化价格的情况
dp[i]=min(dp[i],(sum[i]-sum[j]+10)*p[i]+dp[j]);  //枚举j，价格优化
dp[0]=0;  //Dp初始化
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXN 110
int dp[MAXN];
int sum[MAXN];

int min(int a,int b){
	return a>b?b:a;
}
int main(){
	int cases;
	freopen("1260.txt","r",stdin);
	scanf("%d",&cases);
	while(cases--){
		int n;
		scanf("%d",&n);
		
		int perls[n+1][2];
		sum[0] = 0;
		for(int i = 1;i<=n;i++){
			scanf("%d%d",&perls[i][0],&perls[i][1]);
			sum[i] = sum[i-1]+perls[i][0];
		}
		dp[0]=0;
		for(int i = 1;i<=n;i++){
			dp[i] = dp[i-1]+(perls[i][0]+10)*perls[i][1];
			for(int j =0;j<i;j++){
				dp[i]=min(dp[i],dp[j]+(sum[i]-sum[j]+10)*perls[i][1]);
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}