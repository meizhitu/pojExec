/*
成段更新线段树。用mark延迟标记，在更新的时候不用每次把叶子节点全部更新，
只需要把需要更新的一段所需要更新的权值标记一下，然后在下次查询的时候。
如果需要更新这个被标记的子节点。那么把这个子节点的儿子节点的延迟mark加上父亲节点的mark。
11888710	momoliu	3468	Accepted	7120K	1704MS	C++	2248B	2013-07-31 10:33:56
		*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
		using namespace std;
#define MAX 100001
long long numbers[MAX];
typedef struct Node{
	int r, l;
	long long sum;
	long long added;
}Node;
Node nodes[MAX*4];
void build(int l,int r,int idx){
	nodes[idx].l = l;
	nodes[idx].r = r;
	nodes[idx].sum = 0;
	nodes[idx].added = 0;
	if(l==r){ 
		nodes[idx].sum = numbers[l];
		return;
	};
	int mid=(l+r)>>1;
	build(l,mid,idx<<1);
	build(mid+1,r,idx<<1|1);
	nodes[idx].sum = nodes[idx<<1].sum+nodes[idx<<1|1].sum;
}
long long inc(Node node){
	return node.added*(node.r-node.l+1);
}
long long sum(Node node){
	return node.sum+inc(node);
}
void push_down(int idx){
	if(nodes[idx].l==nodes[idx].r) return;
	long long add = nodes[idx].added;
	nodes[idx<<1].added += add ;
	nodes[idx<<1|1].added += add ;
	nodes[idx].sum += inc(nodes[idx]);		
	nodes[idx].added=0;
}


void update(int s,int e, long long inc,int idx){
	if(nodes[idx].l==s && nodes[idx].r==e){
		nodes[idx].added += inc;
		return;
	}
	//注意此处，之前一直超时，改成下面就好了。
	nodes[idx].sum += (e-s+1)*inc;
	int mid = (nodes[idx].l+nodes[idx].r)>>1;
	if(e<=mid)
		update(s,e,inc,idx<<1);
	else if(s>mid)
		update(s,e,inc,idx<<1|1);
	else
	{
		update(s,mid,inc,idx<<1);
		update(mid+1,e,inc,idx<<1|1);
	}
}
long long query(int l,int r,int idx){
	if(nodes[idx].l==l&&nodes[idx].r==r){
		return sum(nodes[idx]);
	}
	//此处之前写的added>0，理解错误，应该增量可以为负值。
	if(nodes[idx].added!=0){
		push_down(idx);
	}
	int mid = (nodes[idx].l+nodes[idx].r)>>1;
	if(r<=mid)
		return query(l,r,idx<<1);
	else if(l>mid)
		return query(l,r,idx<<1|1);
	else
	{
		return query(l,mid,idx<<1)+query(mid+1,r,idx<<1|1);
	}
}
int main(){
	int N,Q;
	freopen("3468.txt","r",stdin);
	scanf("%d%d",&N,&Q);
	for(int i = 1; i <= N;i++){
		scanf("%lld",&numbers[i]);
	}
	build(1,N,1);
	char op;
	int s,e;
	long long inc;
	for(int j = 1; j<=Q;j++){
		getchar();
		scanf("%c%d%d",&op,&s,&e);
		if(op=='Q'){
			if(s>e){
				int tmp = s;
				s = e ;
				e = s;
			}
			printf("%lld\n",query(s,e,1));
		}
		else{
			scanf("%lld",&inc);
			if(s>e){
				int tmp = s;
				s = e ;
				e = s;
			}
			update(s,e,inc,1);
		}
	}
	return 0;
}