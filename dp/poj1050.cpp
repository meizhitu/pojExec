//这个题目很经典，需要多关注
//把二维矩阵压成了一维数组，然后计算数组的最大连续子串就可以了。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,a[101][101];
int s[101];
int ma(int *p){  //————最大子序列的和，并返回最大值
	int i,max=-(1<<30),b;
	b=p[1];
	for(i=2;i<=n;i++)
	{
		if(b<0)b=p[i];
		else b=b+p[i];
		if(max<b)max=b;
	}
	return max;   
}

int main(){
	int i,j,l,k,max=-(1<<30),t;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	memset(s,0,sizeof(s));
	for(l=1;l<=n;l++) //—————代表结束行
	{
		for(i=1;i<=n;i++)//——————代表起始行
		{ 
			for(j=i;j<=l;j++)
				for(k=1;k<=n;k++)
					s[k]+=a[j][k];//——————s[k]中存第k列从i到l的所有数的和
			t=ma(s);
			if(max<t)max=t;                     
			memset(s,0,sizeof(s));
		}
	}
	printf("%d\n",max);
	return 0;
}