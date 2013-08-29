//给出多对关系，判断是否为树。
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <string>
#include <set>

using namespace std;
#define MAXNODE 1000
int f[MAXNODE];
int err,nodes;
typedef struct node{
	int s;
	int e;
}Node;
int find(int x){
	if(x == f[x]) return x;
	return find(f[x]);
}
int join(Node node){
	int fx = find(node.s);
	int fy = find(node.e);
	if(fx == fy) return -1;
	f[fy] = fx;
	return 1;
}
void init(){
	for(int i = 1;i<=MAXNODE-1;i++)
		f[i]=i;
	err = 0;
	nodes = 0;
}
/*
需要确定所输入的数字中，没有1个以上的根。
*/
int checkroot(set<int>index){
	int equals = 0;
	set<int>::iterator it;
	for(it=index.begin(); it!=index.end();it++){
		int idx = (*it);
		if(idx==f[idx]){
			equals ++;
		}
	}
	if(equals == 1)
		return 1;
	return -1;
}
int main(){
	freopen("1308.txt","r",stdin);
	int s,e,cases=1;
	set<int> index;
	
	init();
	index.clear();
	while(scanf("%d%d",&s,&e))
	{
		if(s == -1 && e==-1) break;
		if(s==0 && e==0){ 
			if(err == 0){
				if(nodes == 0 ||checkroot(index)==1)
					printf("Case %d is a tree.\n",cases);
				else
					printf("Case %d is not a tree.\n",cases);
			}
			else
				printf("Case %d is not a tree.\n",cases);
			cases++;
			init();
			index.clear();
			
		}
		else{
			index.insert(s);
			index.insert(e);
			nodes ++;
			Node node;
			node.s = s;
			node.e = e;
			if(err == 0){
				if(-1== join(node))
					err = 1;
			}
		}
	}
	return 0;
}