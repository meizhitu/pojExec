#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAXN 1010
double height[MAXN];
int dpInc[MAXN];
int dpReverse[MAXN];
int sum[MAXN];
void LIS(int n){
	for(int i = 1;i<=n;i++){
		dpInc[i]=1;
		for(int j = 1;j<i;j++){
			
			if(height[i]>height[j] && dpInc[i]<dpInc[j]+1){
				dpInc[i] = dpInc[j]+1;
			}
		}
	}
}
void ReverseLIS(int n){
	for(int i = n;i>=1;i--){
		dpReverse[i]=1;
		for(int j = i+1;j<=n;j++){
			if(height[i]>height[j] && dpReverse[i]<dpReverse[j]+1){
				dpReverse[i] = dpReverse[j]+1;
			}
		}
	}
}
int main(){
	int n;
	freopen("1836.txt","r",stdin);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
		scanf("%lf",&height[i]);
	memset(dpInc,1,sizeof(dpInc));
	memset(dpReverse,1,sizeof(dpReverse));
	
	LIS(n);
	ReverseLIS(n);
	
	int max = dpInc[1];
	for(int i = 1;i<n;i++)
		//point!!!!
		//统计从某个点作为左侧最高点时，取i+1后的点作为右侧最高点，这样得出的数列总长度
		for(int j =i+1;j<=n;j++)
			if(max<dpInc[i]+dpReverse[j])
				max = dpInc[i]+dpReverse[j];
	printf("%d\n",n-max);
}
