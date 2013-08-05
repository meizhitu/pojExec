#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 
#include <vector> 
 
#include <algorithm> 
#include <iostream> 
#include <queue> 
#include <set> 
#include <string> 
#define MAXSTICKS 5010
using namespace std;

typedef struct Node{
	int l,w;
}Node;
Node sticks[MAXSTICKS];
int order[MAXSTICKS];
bool cmp(Node a,Node b){
	if(a.l==b.l) return a.w<b.w;
	return a.l<b.l;
}
//!important
int LDes(Node nodes[],int n){
	int len = 1;
	memset(order,0,sizeof(order));
	for(int i = 0 ;i<n;i++){
		int l = 1;
		int r = len;
		while(l<=r){
			int m = (l+r)>>1;
			if(order[m]==nodes[i].w)break;
			else if(order[m]>nodes[i].w)l=m+1;
			else if(order[m] < nodes[i].w) r=m-1;
		}
		if(order[l]<nodes[i].w)
			order[l]=nodes[i].w;
		if(len<l) len = l;
	}
	return len;
}
int main(){
	int cases;
	freopen("1065.txt","r",stdin);
	scanf("%d",&cases);
	for(int i = 0 ;i<cases;i++){
		int n;
		scanf("%d",&n);
		for(int k=0;k<n;k++)
			scanf("%d%d",&sticks[k].l,&sticks[k].w);
		sort(sticks,sticks+n,cmp);
		printf("%d\n",LDes(sticks,n));
		
	}
	return 0;
}
