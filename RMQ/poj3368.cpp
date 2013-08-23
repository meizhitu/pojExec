//计算频度的一道题
//经典题
//-1 -1 1 1 1 1 3 10 10 10
//转换为频度数组为
//1 2 1 2 3 4 1 1 2 3 4
//计算区间内的最大频度，变成了计算新数组的最大值。注意区间的起始位置可能截断一个相同数字串。
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
#define MAXN 100100
 
int num2[MAXN],num[MAXN];
int f[MAXN][100]; //max

void stInit(int n ){
	for(int i=1;i<=n;i++)
		f[i][0] = num[i];
	int k = (int)(log((double)n)/log(2.0));
	for(int j = 1;j<=k;j++)
	for(int i = 1;i+(1<<j)-1<=n;i++){
		f[i][j] = max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
		
}
int rmq_query(int i,int j){
	if(i>j) return 0;
	int k = (int)(log((double)j-i+1)/log(2.0));
	
	return max(f[i][k],f[j-(1<<k)+1][k]);
}
int main(){
	int n ;
	freopen("3368.txt","r",stdin);
	while(scanf("%d",&n) && n){
		int q;
		scanf("%d",&q);
		for(int i = 1;i<=n;i++){
			scanf("%d",&num2[i]);
		}
		num2[0] = 100100;
		for(int i = 1;i<=n;i++){
			if(num2[i]==num2[i-1]) num[i]=num[i-1]+1;
			else num[i] = 1;
		}
		stInit(n);
		
		for(int i = 1;i<=q;i++){
			int l,r;
			scanf("%d%d",&l,&r);
			int t = l;
			while(num2[t]==num2[t-1] && t<=r) t++;
			int query = rmq_query(t,r);
		//	printf("l,t,r,q=%d,%d,%d,%d\n",l,t,r,query);
			printf("%d\n",max(t-l,query));
		}
	}
	return 0;
}