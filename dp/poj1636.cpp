/**
f[i][j] 表示从第二个监狱向第一个监狱调换了j人，从第二个监狱向第一个监狱调换了i人这个状态是否能到达。
	网上找的代码。
*/
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

#define  maxn 500
#define Clear(a,b) memset(a,b,sizeof(a))
//表示无向图
vector <int> links[maxn];

bool dp[maxn][maxn];
int vis[maxn],mark[maxn],sum[2],wy[maxn],wx[maxn];

int dfs(int k)
{
	int m,i;
	if (vis[k]) return 0;
	vis[k] = 1;
	sum[mark[k]]++;
	m = links[k].size();
	for(i = 0;i < m;i++) {
		dfs(links[k][i]);
	}
	return 0;
} 

int work()
{
	int m,r,i,j,k,a,b,n,e,len = 0;
  
	Clear(vis,0);
	Clear(mark,0);
	Clear(dp,0);
	Clear(wx,0);
	Clear(wy,0);
	scanf("%d%d",&m,&e);
  
	for(i = 1;i <= m*2;i++) links[i].clear();
  
	for(i = 1;i <= m;i++) {
		mark[i] = 0;//监狱1的mark标志为0
		mark[i+m] = 1;//监狱2的mark标志为1
	}
	for(i = 1;i <= e;i++) {
		scanf("%d%d",&a,&b);
		b += m;
		links[a].push_back(b);
		links[b].push_back(a);
	}
	for(i = 1;i <= m*2;i++) {
		Clear(sum,0);
		dfs(i);
		if (sum[0] > 0 || sum[1] > 0) {
			wx[++len] = sum[0];
			wy[len] = sum[1];
		}
	} 
	n = m / 2;
	dp[0][0] = 1;
	//for(i = 1;i <= len;i++) printf("wx=%d wy=%d\n",wx[i],wy[i]);
	printf("len=%d\n",len);
	for(i = 1;i <= len;i++)
		for(j = n;j >= wx[i];j--)//否则需要用三维的dp，注意此处的j从n开始，类似01背包的空间优化。
			for(k = n;k >= wy[i];k--)
				dp[j][k] = dp[j][k] || dp[j-wx[i]][k-wy[i]];
	i = n;

	while(dp[i][i] != 1) i--;
	printf("%d\n",i);
	return 0;
}

int main()
{
	int t;
	freopen("1636.txt","r",stdin);
	scanf("%d",&t);
	while(t--) work();
	return 0;
}
