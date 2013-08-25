//张贴海报覆盖问题
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
#define MAXN 10010
typedef struct TNode{
	int l;
	int r;
	int color;
}TNode;
TNode nodes[MAXN*10];

map< int,int> reflect;
int inputs[MAXN][2];
int arr[MAXN*2];
bool visited[MAXN];
int colors = 0;

void init(){
	memset(inputs,0,sizeof(inputs));
	reflect.clear();
	memset(nodes,0,sizeof(nodes));
	memset(visited,false,sizeof(visited));
	colors = 0;
}
bool cmp(int a, int b){
	return a < b;
}
void build(int idx,int l,int r){
	if(r<l+1) return;
	nodes[idx].l = l;
	nodes[idx].r = r;
	nodes[idx].color = 0 ;
	
	int mid = (l+r)>>1;
	if(l+1<r){
		build(2*idx,l,mid);
		build(2*idx+1,mid,r);
	}
}
void insert(int idx,int l,int r,int color){
	if(nodes[idx].l==l && nodes[idx].r==r){
		nodes[idx].color = color;
		return;
	}
	//颜色下移，且本身节点颜色清空。
	if(nodes[idx].color!=0 && nodes[idx].color!=color){
		nodes[2*idx].color = nodes[idx].color;
		nodes[2*idx+1].color = nodes[idx].color;
		nodes[idx].color = 0;
	}
	int mid = (nodes[idx].l+nodes[idx].r)>>1;
	if(l>=mid)
		insert(2*idx+1,l,r,color);
	else if(r<=mid)
		insert(2*idx,l,r,color);
	else{
		insert(2*idx,l,mid,color);
		insert(2*idx+1,mid,r,color);
	}
}
//坐标离散化
int preProcess(int * arr,int k,int n){
	sort(arr,arr+k,cmp);
	int prev = -1;
	int contr = 1;
	for(int i =0 ; i< k;i++){
		if(arr[i]==prev) continue;
		reflect[arr[i]] = contr++;
		prev = arr[i];
	}
	for(int i = 0 ; i<n;i++){
		inputs[i][0] = reflect[inputs[i][0]];
		inputs[i][1] =  reflect[inputs[i][1]];
	}
	return contr-1;
}
void search(int idx){
	if(nodes[idx].color!=0)
		if(!visited[nodes[idx].color])
	{
		colors ++;
		visited[nodes[idx].color] = true;
		return;
	}
	if(nodes[idx].r-nodes[idx].l>0){
		search(2*idx);
		search(2*idx+1);
	}
}
int main(){
	int cases;
	freopen("2528.txt","r",stdin);
	scanf("%d",&cases);
	for(int i =0;i<cases;i++){
		int n ,k = 0;
		init();
		scanf("%d",&n);
		
		for(int j = 0 ; j < n;j++){
			scanf("%d%d",&inputs[j][0],&inputs[j][1]);
			arr[k++] = inputs[j][0];
			arr[k++] = inputs[j][1];
		}
		int max = preProcess(arr,k,n);
		
		build(1,1,max);
		
		for(int j=0;j<n;j++){
			insert(1,inputs[j][0],inputs[j][1],j+1);
		}
		search(1);
		
		printf("%d\n",colors);
	}
	return 0;
}
