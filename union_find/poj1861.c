//最小生成树问题
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

#define MAXHUBS 1100
#define MAXCONNECTIONS 15010
int f[MAXHUBS];
typedef struct node{
	int s;
	int e;
	int l;
}Node;
Node nodes[MAXCONNECTIONS];
Node ret[MAXCONNECTIONS];
bool cmp(Node a,Node b){
	return a.l < b.l;
}

int find(int x){
	if(x == f[x]) return x;
	return find(f[x]);
}
int join(Node node,int *max,int *edges){
	int fx =find(node.s);
	int fy = find(node.e);
	if(fx == fy) return 0;
	if(*max < node.l) *max = node.l;
	(*edges)++;
	f[fy] = fx;
	return 1;
}
int main(){
	int n,m;
	freopen("1861.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i =1;i<=n;i++)
		f[i]=i;
	for(int i = 0;i<m;i++){
		scanf("%d%d%d",&nodes[i].s,&nodes[i].e,&nodes[i].l);
	}
	//使用qsort超时=。=
	//qsort(nodes,m,sizeof(nodes[0]),cmp);
	sort(nodes,nodes+m,cmp);
	
	int max = 0 ;
	int cables = 0 ;
	int k = 0 ;
	for(int i = 0;i<m;i++){
		if(1== join(nodes[i],&max,&cables)){
			ret[k].s = nodes[i].s;
			ret[k].e = nodes[i].e;
			k++;
		}
	}
	printf("%d\n%d\n",max,cables);
	for(int i = 0;i<k;i++){
		printf("%d %d\n",ret[i].s,ret[i].e);
	}
	return 0;
}