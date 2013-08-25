//线段树，太猥琐了！
//求区间内的最大值最小值，可以使用RMQ或者单调数列。
//11943067	momoliu	2823	Accepted	39892K	9391MS	C++	2251B	2013-08-08 13:41:05
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXN 1000010
typedef struct Node{
	int l,h;
	int min,max;
}Node;
Node tree[MAXN<<2];
int arrMin[MAXN];
int arrMax[MAXN];
int len = 1;
#define inf 1<<30
using namespace std;
int min(int a,int b){
	return a>b?b:a;
}
int max(int a,int b){
	return a>b?a:b;
}
void build(int l,int h,int idx){
	tree[idx].l = l;
	tree[idx].h = h;
	tree[idx].min = inf;
	tree[idx].max = -inf ;
	if(l==h) return ;
	int mid = (l+h)>>1;
	build(l,mid,idx<<1);
	build(mid+1,h,idx<<1|1);
}
int queryMin(int l,int h,int idx){
	if(tree[idx].l==l &&tree[idx].h==h)
		//此处找错找了半天，如果需要返回就要清晰的写上return，否则会出现莫名其妙的错误。
 		return tree[idx].min;
	int mid = (tree[idx].l+tree[idx].h)>>1;
 	if(h<=mid)
 		return queryMin(l,h,idx<<1);
	else if(l>mid)
		return queryMin(l,h,idx<<1|1);
	else
		return min(queryMin(l,mid,idx<<1),queryMin(mid+1,h,idx<<1|1));
}
int queryMax(int l,int h,int idx){
	if(tree[idx].l==l &&tree[idx].h==h)
		return tree[idx].max;
	int mid = (tree[idx].l+tree[idx].h)>>1;
	if(h<=mid)
		return queryMax(l,h,idx<<1);
	else if(l>mid)
		return queryMax(l,h,idx<<1|1);
	else
		return max(queryMax(l,mid,idx<<1),queryMax(mid+1,h,idx<<1|1));
}

void update(int l ,int h,int idx,int num){
	if(tree[idx].l == l && tree[idx].h==h)
	{
		tree[idx].min = tree[idx].max = num;
		return;
	}
	int mid = (tree[idx].l+tree[idx].h)>>1;
	if(h<=mid)
		update(l,h,idx<<1,num);
	else if(l>mid)
		update(l,h,idx<<1|1,num);
	else{
		update(l,mid,idx<<1,num);
		update(mid+1,h,idx<<1|1,num);
	}
	tree[idx].min = min(tree[idx<<1].min,tree[idx<<1|1].min);
	tree[idx].max = max(tree[idx<<1].max,tree[idx<<1|1].max);
 }
 
int main(){
	int n,k;
	freopen("2823.txt","r",stdin);
	scanf("%d%d",&n,&k);
	build(1,n,1);
	int num;
	for(int i = 1;i<=n;i++){
		scanf("%d",&num);
		update(i,i,1,num);
	}
	for(int i=1;i<=n-k+1;i++){
		int end = i+k-1;
		if(i+k-1>n)
			end = n;
		arrMin[len] = queryMin(i,end,1);
		arrMax[len] = queryMax(i,end,1);
		len ++;
	}
	for(int i = 1;i < len-1;i++)
		printf("%d ",arrMin[i]);
	printf("%d\n",arrMin[len-1]);
	for(int i = 1;i < len-1;i++)
		printf("%d ",arrMax[i]);
	printf("%d\n",arrMax[len-1]);
}
