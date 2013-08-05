#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXD 105
#define MAX 10000000
int dp[MAXD][1000];//第i件设备，网络带宽为j，所获得的最小价格。
				  //dp[i][min(j,band[i])]=min(dp[i][min(j,band[i])],dp[i][j]+price[i])
int band[MAXD];
int price[MAXD];
int min(int a,int b){
	return a>b?b:a;
}
double maxF(double a,double b){
	return a>b?a:b;
}
int main(){
	int cases;
	freopen("1018.txt","r",stdin);
	scanf("%d",&cases);
	while(cases--){
		int devices;
		for(int i=0;i<MAXD;i++)
			for(int j =0;j<1000;j++)
				dp[i][j] = MAX;
		scanf("%d",&devices);
		dp[0][0] = 0;
		int maxband = -1;
		for(int i = 1;i <= devices;i++){
			int manufacturers = 0;
			scanf("%d",&manufacturers);
			for(int j = 1;j<=manufacturers;j++){
				scanf("%d%d",&band[j],&price[j]);
				if(maxband<band[j])
					maxband = band[j];
				if(i==1)
					dp[i][band[j]]=min(dp[i][band[j]],price[j]);
 				
			}	
			if(i>1)
				for(int j=1;j<=manufacturers;j++)
					for(int k=0;k<=maxband && i>1;k++)
				{
					if(dp[i-1][k]!= MAX){
						int idx = min(k,band[j]);
						dp[i][idx]=min(dp[i-1][k]+price[j],dp[i][idx]);
					}
				}
			
 		}
		double maxBP= -1;
		for(int j=1;j<=maxband;j++)
			if(dp[devices][j]!=MAX){
				maxBP = maxF(maxBP,j*1.0/dp[devices][j]);
			}
		printf("%.3lf\n",maxBP);
	}
	return 0;
}