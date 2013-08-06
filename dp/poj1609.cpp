/*求最长非降子序列问题*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 10010
int dp[MAXN];
typedef struct Node{
	int l,m;
}Block;
Block blocks[MAXN];
bool cmp(Block a,Block b ){
	if(a.l == b.l) return a.m<b.m;
	return a.l<b.l;
}
int main(){
	int n ;
	freopen("1609.txt","r",stdin);
	while(~scanf("%d",&n) && n){
		for(int i = 1; i <=n;i++)
			scanf("%d%d",&blocks[i].l,&blocks[i].m);
		sort(blocks+1,blocks+1+n,cmp);
		memset(dp,0,sizeof(dp));
		dp[1] = 1;
		for(int i = 2;i<=n;i++)
		{
			dp[i] = 1;
			for(int j = 1;j<i;j++){
				if(blocks[j].m<=blocks[i].m && dp[i]<dp[j]+1)
					dp[i] = dp[j]+1;
			}
		}
		int max = dp[1];
		for(int i = 1;i<=n;i++)
			if(max < dp[i])
				max = dp[i];
		printf("%d\n",max);
	}
	printf("*\n");
	return 0 ;
}
