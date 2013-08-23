/*
左侧城市编号1-N，右侧城市编号1-M，K个从N到M的连接，求出交叉的次数。记住从左侧往右侧看。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
#define maxN 1010
int c[maxN];
typedef struct Node{
	int s,t;
}Node;
bool cmp(Node a,Node b){
	//注意这里的排序算法。
	if(a.s == b.s)return a.t > b.t;
	return a.s > b.s;
}
int lowBit(int x){
	return x&(-x);
}
void update(int idx){
	while(idx<maxN){
		c[idx]++;
		idx += lowBit(idx);
	}
}
int sum(int idx){
	int ret = 0;
	while(idx>0){
		ret += c[idx];
		idx -= lowBit(idx);
	}
	return ret;
}
Node nodes[1000010];
int main(){
	int cases;
	freopen("3067.txt","r",stdin);
	scanf("%d",&cases);
	int iCases = 1;
	while(cases--){
		int n,m,k;
		memset(c,0,sizeof(c));
		if(EOF==scanf("%d%d%d",&n,&m,&k))return 0;
		for(int i = 1;i<=k;i++){
			scanf("%d%d",&nodes[i].s,&nodes[i].t);
		}
		sort(nodes+1,nodes+k+1,cmp);
		long long ret = 0 ;
		//我日必须改成long long 才能过
		for(int i = 1;i<=k;i++){
			ret +=sum(nodes[i].t-1);
			update(nodes[i].t);
		}
        printf("Test case %d: %lld\n",iCases++,ret);
	}
	
	return 0;
}
