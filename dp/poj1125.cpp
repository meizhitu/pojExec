//求最短路径的一道题
//11917068	momoliu	1125	Accepted	408K	0MS	G++	1386B	2013-08-04 13:26:31
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 105
#define inf 10000000
int distance[MAXV][MAXV];
int maxV(int a[],int n ){
	int max = -1;
	for(int i = 1;i<=n;i++){
		if(max < a[i])
			max = a[i];
	}
	return max;
}
int minV(int a[],int n,int *loc){
	int min = inf;
	*loc = 0;
	for(int i = 1;i<=n;i++){
		if(min > a[i]){
			min = a[i];
			*loc = i;
		}
	}
	return min;
}
void floyd_w(int n ){
	for(int k = 1;k<=n;k++)
		for(int i = 1;i<=n;i++)
		for(int j =1;j<=n;j++){
			if(i!=j && distance[i][j]>(distance[i][k]+distance[k][j]))
				distance[i][j] = distance[i][k]+distance[k][j];
		}
		 
	int max[n];
	for(int i = 1;i<=n;i++)
		max[i] = maxV(distance[i],n);
	int minLoc;
	int minTime = minV(max,n,&minLoc);
	if(minTime == inf)
		printf("disjoint\n");
	else
		printf("%d %d\n",minLoc,minTime);
}
void init(){
	for(int i = 0;i<MAXV;i++)
	for(int j = 0;j<MAXV;j++){
		if(i==j)
			distance[i][j] = 0;
		else
			distance[i][j]=inf;
	}
}
int main(){
	int n;
	freopen("1125.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		init();
		//	memset(distance,inf,sizeof(distance));
		for(int i = 1;i<=n;i++){
			int pairs,l,k;
			scanf("%d",&pairs);
			for(int j= 1;j<=pairs;j++){
				scanf("%d%d",&l,&k);
				distance[i][l] = k;
			}
		}
		floyd_w(n);
	}
	return 0;
}