#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits>
#define MID(x,y) ((x+y)>>1)
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define BUG printf("here!!!\n");

using namespace std;

const int MAX = 5010;
struct Tnode{ int l,r,num,len,cover;bool lb,rb;};
struct Sline{ int x,y1,y2,flag;};
Tnode node[MAX<<2];
Sline l[MAX<<1];
int y[MAX<<1];

void add_line(int x1,int y1,int x2,int y2,int &cnt)
{
	l[cnt].x = x1; l[cnt].y1 = y1; l[cnt].y2 = y2; l[cnt].flag = 1;
	y[cnt++] = y1;
	l[cnt].x = x2; l[cnt].y1 = y1; l[cnt].y2 = y2; l[cnt].flag = -1;
	y[cnt++] = y2;
}
void init()
{
	memset(node,0,sizeof(node));
}
void Build(int t,int l,int r)
{
	node[t].l = l; node[t].r = r;
	node[t].num = 0;
	if( l == r - 1 ) return ;
	int mid = MID(l,r);
	Build(R(t),mid,r);
	Build(L(t),l,mid);
}
void Updata_len(int t)
{
	if( node[t].cover > 0 )
	{
		node[t].num = node[t].lb = node[t].rb = 1;
		node[t].len = y[node[t].r] - y[node[t].l];
	}
	else
		if( node[t].l == node[t].r - 1 )
			node[t].rb = node[t].lb = node[t].len = node[t].num = 0;
		else
		{
			node[t].rb = node[R(t)].rb; node[t].lb = node[L(t)].lb;
			node[t].len = node[L(t)].len + node[R(t)].len;
			node[t].num = node[L(t)].num + node[R(t)].num - node[R(t)].lb*node[L(t)].rb;
		}		//两线段重合的话，得减一下。。 
}
void Updata(int t,Sline p)
{
	if( y[node[t].l] >= p.y1 && y[node[t].r] <= p.y2 )
	{
		node[t].cover += p.flag;
		Updata_len(t);
		return ;
	}
	if( node[t].l == node[t].r - 1 ) return ;
	int mid = MID(node[t].l ,node[t].r);
	if( p.y1 <= y[mid] ) Updata(L(t),p);
	if( p.y2 > y[mid] ) Updata(R(t),p);
	Updata_len(t);
}
int solve(int n,int cnt,Sline *l)
{
	init();
	Build(1,0,cnt-1);
	int ans = 0,last = 0,lines = 0;
	for(int i=0; i<n; i++)
	{
		Updata(1,l[i]);
		if( i >= 1 )
			ans += 2 * lines * (l[i].x - l[i-1].x);//计算平行于x轴的长度 
		ans += abs(node[1].len - last);		   // 计算平行于y轴的长度
		last = node[1].len; 
		lines = node[1].num;
	}
	return ans;
}

bool cmp(Sline a,Sline b)
{
	if( a.x == b.x ) return a.flag > b.flag;
	return a.x < b.x;
}
int main()
{
	int n,x1,x2,y1,y2;
	
	while( ~scanf("%d",&n) )
	{
		if( n == 0 )
		{
			printf("0\n");
			continue;
		} 
		int cnt = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			add_line(x1,y1,x2,y2,cnt);
		}
		sort(y,y+cnt);
		sort(l,l+cnt,cmp);
		int t = cnt;
		t = unique(y,y+cnt) - y;
		int ans = solve(cnt,t,l);
		printf("%d\n",ans);
	}

return 0;
}

