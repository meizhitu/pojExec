/*
插队问题。
这个题目主要是考虑从后往前填，这样就方便操作了。
其中peo[rt]表示以rt为根的左右子树中总共存在的空位数，
其实每个元素的pos[i]就可以表示前面有pos[i]个空位，这样就可以进行插入了。
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#define MAXN 200010
using namespace std;
typedef struct node{
	int l,r;
	int counter;
}Node;
Node TNode[MAXN*10];
int order[MAXN];
void build(int l,int r,int idx){
	TNode[idx].l = l;
	TNode[idx].r = r;
	TNode[idx].counter = r-l+1;
	if(l == r )return;
	int mid = (l+r)>>1;
	build(l,mid,2*idx);
	build(mid+1,r,2*idx+1);
}
void update(int idx,int pos,int val){
	TNode[idx].counter --;
	if(TNode[idx].l == TNode[idx].r){
		order[TNode[idx].l] = val;
		return;
	}
	if(pos <= TNode[2*idx].counter) update(2*idx,pos,val);
	else
	{
		pos -= TNode[2*idx].counter;
		update(2*idx+1,pos,val);
	}
}
int main(){
	int n ;
	freopen("2828.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		memset(TNode,0,sizeof(TNode));
		memset(order,0,sizeof(order));
		
		int pos[n];
		int val[n];
		for(int i = 0 ; i<n;i++){
			scanf("%d%d",&pos[i],&val[i]);
			pos[i]++;
		}
		build(1,n,1);
		/*逆序非常important*/
		for(int i = n-1 ;i>=0;i--)
			update(1,pos[i],val[i]);
		for(int i =1;i <=n;i++)
			printf("%d ",order[i]);
		printf("\n");
	}

}

