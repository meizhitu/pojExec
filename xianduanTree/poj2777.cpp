/*
基础的线段树，但其中的第一次染色，和最后的查找操作需要注意。
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 100010
typedef struct Node{
	int l,r;
	int c;
}Node;
Node tNodes[MAXN*4];
bool visited[35];
int colors = 0;
void build(int l,int r,int idx){
	tNodes[idx].l = l;
	tNodes[idx].r = r;
	if(l==r) return;
	int mid = (l+r)>>1;
	build(l,mid,2*idx);
	build(mid+1,r,2*idx+1);
}
void update(int idx,int l,int r, int color){
	if(tNodes[idx].l==l && tNodes[idx].r==r){
		tNodes[idx].c = color;
		return ;
	}
	if(tNodes[idx].c!=0 && tNodes[idx].c!=color){
		int c = tNodes[idx].c;
		tNodes[2*idx].c = c;
		tNodes[2*idx+1].c = c;
		tNodes[idx].c = 0;
	}
	int mid = (tNodes[idx].l+tNodes[idx].r)>>1;
	if(l>=mid+1)
		update(2*idx+1,l,r,color);
	else if(r<=mid)
		update(2*idx,l,r,color);
	else
	{
		update(2*idx,l,mid,color);
		update(2*idx+1,mid+1,r,color);
	}
}
void search(int idx,int l,int r){
	if(tNodes[idx].c!=0){
		if(!visited[tNodes[idx].c])
		{
			colors ++;
			visited[tNodes[idx].c] = true;
			return;
		}
	}
	else{
		int mid = (tNodes[idx].l+tNodes[idx].r)>>1;
		if(l>=mid+1)
			search(2*idx+1,l,r);
		else if(r<=mid)
			search(2*idx,l,r);
		else
		{
			search(2*idx,l,mid);
			search(2*idx+1,mid+1,r);
		}
	}
}
int main(){
	int L,T,O;
	freopen("2777.txt","r",stdin);
	scanf("%d%d%d",&L,&T,&O);
	build(1,L,1);
	//关键点在于不能把每个节点都颜色都直接设置为1，而应该按照线段树的定义把root的color设置为1 ！！！
	tNodes[1].c =1;
	for(int i = 0 ;i < O;i++){
		char op;
		int A,B,C;
		//过滤到换行符
		getchar();
		
		if(op=='\n')
			scanf("%c",&op);
		
		if(op=='C'){
			scanf("%d%d%d",&A,&B,&C);
			if(A>B){	
				int t = A;
				A=B;
				B=t;
			}
			update(1,A,B,C);
		}
		else if(op=='P'){
			scanf("%d%d",&A,&B);
			if(A>B){	
				int t = A;
				A=B;
				B=t;
			}
			colors = 0;
			memset(visited,false,sizeof(visited));
			
			search(1,A,B);
			printf("%d\n",colors);
		
		}
		
	
	
	}
	return 0;
}