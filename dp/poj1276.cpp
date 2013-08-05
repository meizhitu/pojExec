//有各种不同面值的货币，每种面值的货币有不同的数量，请找出利用这些货币可以凑成的最接近且小于等于给定的数字cash的金额。f[i][v]表示前i种面额组成金额为v的可行性。利用01背包进行优化。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INF 0x3f3f3f
bool f[100000];
int main(){
	int cash;
	int num;
	int input[30];
	while(scanf("%d",&cash)!=EOF){

		int i,j;
		int n[10],d[10];
		scanf("%d",&num);
		for(i = 0 ;i<=cash;i++)
			f[i] = false;
		f[0]=true;
		for(i = 0; i < num;i ++)
			scanf("%d%d",&n[i],&d[i]);
		if(num == 0 || cash == 0){
			printf("0\n");
			continue;
		}
		for(i = 1; i <= num;i++)
		{
			if(n[i-1]*d[i-1] > cash ) //complete package
			{
				for( j = d[i-1];j<=cash;j++)
 					f[j] = f[j]||f[j-d[i-1]];
			}
			else{
				int k = 1;
				int c = n[i-1];
				while(k<c){
					for(j=cash;j>=k*d[i-1];j--)
						if(f[j-k*d[i-1]]>-INF)
							f[j] = f[j]||f[j-k*d[i-1]];//+k*1?f[j]:f[j-k*d[i-1]]+k*1;
					c -= k;
					k+=k;
				}
				if(c>0)
					for(j=cash;j>=c*d[i-1];j--)
						if(f[j-c*d[i-1]]>-INF)
							f[j] = f[j]||f[j-c*d[i-1]];//+c?f[j]:f[j-c*d[i-1]]+c;
			}
		}
		for(j = cash;j>=0;j--)
		{
			if(f[j]){
				printf("%d\n",j);
				break;
			}
		}
	}
}
