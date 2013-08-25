#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <ctime>
using namespace std;
#define LL long long
const int N = 10005;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int sum[N<<2];
int tree[N<<2][2];

void PushUp(int rt)
{
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void build(int l,int r,int rt)
{
	tree[rt][0] = l;
	tree[rt][1] = r;
	if(l == r)
	{
		sum[rt] = 1;
		return;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	PushUp(rt);
}

int update(int p,int rt)
{
	sum[rt] --;
	if(tree[rt][0] == tree[rt][1])
	{
		sum[rt] = 0;
		return tree[rt][0];//从绝对位置剔除
	}
	if(p <= sum[rt<<1]) return update(p,rt<<1);
	else return update(p-sum[rt<<1],rt<<1|1);
	PushUp(rt);
}

int main()
{

	int n,m;
	while(~scanf("%d %d",&n,&m))
	{
		build(1,n,1);
		for(int i = 1 ; i <= 15 ;  i ++) cout<<sum[i]<<" "<<tree[i][0]<<" "<<tree[i][1]<<endl;
		int pos = 1;
		int seq = 1;
		for(int i = 0 ; i < n ; i++)
		{
			//这里才是约瑟夫环的关键，seq表示的是当前人数中需要删除的人的标号。
			seq = (seq + m - 1) % sum[1];//seq 只是相对位置,sum[1]为整棵树所拥有的活的节点数
			if(seq == 0) seq = sum[1];
			cout<<"seq = "<<seq<<"; ";
			pos = update(seq,1);
			cout<<pos<<" ";
		}
	}
	return 0;
}
