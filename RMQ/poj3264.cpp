//RMQ的典型应用
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
#define maxN 50100
int f1[maxN][100];
int f2[maxN][100];
int num[maxN];
void stInit(int n ){
	int k = (int)(log((double)n)/log(2.0));
	for(int i = 1;i<=n;i++)
	{
		f1[i][0] = num[i];
		f2[i][0] = num[i];
	}
	for(int j = 1;j<=k;j++)
		for(int i =1;i+(1<<j)-1<=n;i++){
			int m = i+(1<<(j-1));
			f1[i][j] = max(f1[i][j-1],f1[m][j-1]);
			f2[i][j] = min(f2[i][j-1],f2[m][j-1]);
		}
}
int rmqMax(int i,int j)
{
	if( i > j ) return 0;
	int m = (int)(log((double)(j-i+1))/log(2.0));
	return max(f1[i][m],f1[j-(1<<m)+1][m]);
}

int rmqMin(int i,int j)
{
	if( i > j ) return 0;
	int m = (int)(log((double)(j-i+1))/log(2.0));
	return min(f2[i][m],f2[j-(1<<m)+1][m]);
}
int main(){
	int n,q;
	freopen("3264.txt","r",stdin);
	scanf("%d%d",&n,&q);
	for(int i = 1; i<=n;i++){
		scanf("%d",&num[i]);
	}
	stInit(n);
	for(int i = 1;i<=q;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		int shortest = rmqMin(l,r);
		int heighest = rmqMax(l,r);
		//printf("%d,%d\n",shortest,heighest);
		printf("%d\n",heighest-shortest);
	}
}
