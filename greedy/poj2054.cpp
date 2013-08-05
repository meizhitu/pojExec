/*
非常经典的一道贪心，合并父子节点来减小问题规模
贪心原则应该是Ci大的尽量先染色，但是由于父节点染了才能染子节点的限制使得问题不好解决了，
但是Ci大的一定是在其父节点染色后立即被染色，这时大牛们的思路我也没有看明白如何证明的，但仔细一想就明白了。
于是我们根据这个条件就可以将Ci大的点与其父节点合并在一起组成一个集合。这样就可以将问题规模减小。
	*/
#include<iostream>
#include<cstring>
#include<cstdio>
	using namespace std;
#define maxn 1010
int n,root,ans;
int parent[maxn];
bool visited[maxn];
struct node
{
	int factor,numbers;
	int ans;
}a[maxn];
void init()
{
	for(int i=1;i<=n;i++)
		parent[i]=i;
	memset(visited,0,sizeof(visited));
	ans=0;
}
int find_parent(int x)
{
	if(x==parent[x]) return x;
	int p =parent[x];
	while(visited[p] == 1){
		p = parent[p];
	}
	return p;
}
inline void union_parent(int x,int y)
{
	parent[y]=x;
}

int findMax(){
	float max = 0 ;
	int maxIdx = 0;
	float ratio;
	for(int i=1;i<=n;i++)
	if(!visited[i] && i!= root && (ratio=a[i].factor*1.0/a[i].numbers)>max){
		max = ratio;
		maxIdx = i;
	}
	return maxIdx;
}
int main()
{
	int i,j,x,y;
	freopen("2054.txt","r",stdin);
	while(scanf("%d%d",&n,&root)&&n)
	{
		init();
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i].factor);
			a[i].numbers=1;
			a[i].ans = 0;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			union_parent(x,y);
		}
		for(i=1;i<n;i++)
		{
			int maxIdx = findMax();
			int parentIdx = find_parent(maxIdx);
			a[parentIdx].ans += a[maxIdx].ans+a[parentIdx].numbers*a[maxIdx].factor;
			a[parentIdx].factor +=a[maxIdx].factor;
			a[parentIdx].numbers += a[maxIdx].numbers;
			visited[maxIdx] = 1;
		}
		printf("%d\n",(a[root].ans+a[root].factor));
	}
}