//dp[i][j]=dp[i-1][j-1]*P(a[i]和已有的所有巧克力颜色不同)=dp[i-1][j-1]*(c-(j-1))/c
//        =dp[i-1][j+1]*P(a[i]和已有的某个巧克力颜色相同，导致吃了2个)=dp[i-1][j+1]*(j+1)/c
//dp[N][M]/(dp[N][1]+...+dp[N][N])(dp为bool)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1005
double dp[2][MAX];
void init(int c,int n){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
}
int main(){
	int c,m,n;
	while(scanf("%d",&c) && c){
		scanf("%d%d",&n,&m);
		init(c,n);
		
		if(m>n||m>c||(n+m)%2==1){
			printf("0.000\n");
			continue;
		}
		//据说这个公式是收敛的=、=
		if(n>1000)
			n=1000+n%2;
		for(int i = 1;i<=n;i++)
			for(int j=0;j<=c;j++)
		{
			if(j==0)
				dp[i%2][j] = 1.0* dp[(i-1)%2][j+1]*(j+1)/c;
			else if(j==c)
				dp[i%2][j] = 1.0* dp[(i-1)%2][j-1]*(c-j+1)/c;
			else
				dp[i%2][j] = 1.0*dp[(i-1)%2][j-1]*(c-(j-1))/c+1.0*dp[(i-1)%2][j+1]*(j+1)/c;
		}
		printf("%.3f\n",dp[n%2][m]);
	}
	return 0;
}