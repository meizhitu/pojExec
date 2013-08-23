/*
dp[i][j]表示以a[j]为结尾的长度为i的递增序列的个数。
dp[i][j]=sum(dp[i-1][k])(k<j,a[k]<a[j])
解题思路：设置5个树状数组，分别表示：以a[i]结尾的长度为1，2，3，4，5的数组个数。
	以2，1，3，4，5为例：
		在插入2的时候，数组1为：0 1 0 0 0 0
		数组2-5均全部为0.
		在插入1后，数组1为：1 1 0 0 0 0 0
		数组2-5也全部为0。
		在插入3后，数组1为：1 1 1 0 0 0 0
		数组2为：0 0 2 0 0 0 0（因为3插入数组1的时候，数组2对应的3的位置的大小取决于数组1中比3小的数字的和。）
		插入4后，数组1为：1 1 1 1 0 0
		数组2为：0 0 2 3 0 0 
		数组3为：0 0 0 2 0 0 		
						
*/
//网上找的代码
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
typedef unsigned long long ll;
using namespace std;
const int maxn=5e4+9;
ll tree[6][maxn],dp[maxn][6];
int a[maxn];
int n;

typedef struct node
{
	int data,id;
	bool operator <(const node &xx) const
	{
		if(data==xx.data)
			return(id<xx.id);
		return(data<xx.data);
	}
};

int lowbit(int x)
{
	return(x&-x);
}

void insert(int x,int t,ll tmp)
{
	for(int i=x;i<=n;i+=lowbit(i))
		tree[t][i]+=tmp;
}

ll getsum(int x,int t)
{
	ll ans=0;
	for(int i=x;i>=1;i-=lowbit(i))
		ans+=tree[t][i];
	return(ans);
}

int main()
{
	set <node> d;
	while(scanf("%d",&n)!=EOF)
	{
		d.clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			node x;
			x.data=a[i];
			x.id=i;
			d.insert(x);
		}
		int k=0,tmp;
		for(set <node>::iterator i=d.begin();i!=d.end();i++)
		{
			if(i==d.begin()||i->data!=tmp) k++;
			a[i->id]=k;
			tmp=i->data;
		}

		memset(dp,0,sizeof(dp));
		memset(tree,0,sizeof(tree));
		//主要部分在这里！!
		for(int i=1;i<=n;i++)
		{
			dp[i][1]=1;
			insert(a[i],1,dp[i][1]);
			for(int j=1;j<=4;j++)
			{
				dp[i][j+1]=getsum(a[i]-1,j);
				insert(a[i],j+1,dp[i][j+1]);
			}
		}
		//后面是为了通过poj而做的优化，暂时不看了。
		ll ans=0,ans1=0;
		for(int i=1;i<=n;i++)
		{
			ans+=dp[i][5];
			ans1+=ans/ll(1000000000000000);
			ans%=1000000000000000;
		}
		if(ans1)
		{
			printf("%lld",ans1);
			printf("%015lld\n",ans);
		}
		else
			printf("%lld\n",ans);
	}
	return 0;
}
			