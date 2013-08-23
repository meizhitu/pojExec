#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAX(a,b) (a>b?a:b)
#define ABS(a) ((a)>0?(a):-1*(a))
#define TK(a) (a&(a^(a-1)))
#define N 20005
using namespace std;

struct Node
{
    long long v,x;
    bool operator<(const Node & a)const
    {
        return v<a.v;
    }
}node[N];

long long num[2][N];

int lowBit(int x){
	return x&(-x);
}
long long rsum(int pos,int d)
{
    long long ans=0;
    while(pos>0)
    {
        ans+=num[d][pos];
        pos-=lowBit(pos);
    }
    return ans;
}

void update(int pos,long long v,int d)
{
    while(pos<=20000)
    {
        num[d][pos]+=v;
        pos+=lowBit(pos);
    }
}

int main()
{
    int n;
	freopen("1990.txt","r",stdin);
    scanf("%d",&n);
    memset(num,0,sizeof(num));
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&node[i].v,&node[i].x);
    sort(node+1,node+1+n);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        long long a=rsum(node[i].x,0),b=rsum(node[i].x,1);
		printf("%d,%d\n",a,b);
        ans+=(node[i].x*a-b+rsum(20000,1)-b-(i-1-a)*node[i].x)*node[i].v;
		printf("ans=%d\n",ans);
        update(node[i].x,1,0);
        update(node[i].x,node[i].x,1);
    }
    printf("%lld\n",ans);
}