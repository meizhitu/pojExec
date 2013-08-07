/*
由图论知识可以知道，无向图存在欧拉路的充要条件为：
	①     图是连通的；
		②     所有节点的度为偶数，或者有且只有两个度为奇数的节点。
*/
//这道题手贱写错了一个地方，RE！
//11938531	momoliu	2513	Accepted	78120K	1235MS	G++	1616B	2013-08-07 16:46:24
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
using namespace std;
typedef struct Node{
	Node * nodes[27];
	int id;
	int times;
	bool existed;
}Node;
Node *root = 0;
int colors = 1;
const int maxN =550000;
int array[maxN];
int pa[maxN];
Node * createNode(){
	Node * node = (Node*)malloc(sizeof(Node));
	node->id = 0;
	node->existed = false;
	node->times = 1;
	memset(node->nodes,0,sizeof(node->nodes));
	return node;
}
int insert(char s[]){
	if(!root)
		root = createNode();
	Node *p = root;
	int len = strlen(s);
	for(int i = 0 ;i<len;i++)
	{
		int idx = s[i]-'a';
		if(!p->nodes[idx])
			p->nodes[idx] = createNode();
		p = p->nodes[idx];
	}
	if(p->existed)
		p->times ++;
	else
	{
		p->existed = true;
		p->id = colors++;
	}
	array[p->id] = p->times;
	return p->id;
}
int find(int x){
	if(x==pa[x])return x;
	int t = find(pa[x]);
	pa[x] = t;
	return t;
}
int main(){
	char s[15];
	char t[15];
	freopen("2513.txt","r",stdin);
	for(int i = 0;i<maxN;i++)
		pa[i] = i;
	while(scanf("%s%s",s,t)!=EOF){
		int id1=insert(s);
		int id2=insert(t);
		int x = find(id1);
		int y = find(id2);
		pa[x] = y;
	}
	int odd = 0 ;
	for(int i = 1;i<colors;i++)
		if(array[i]%2!=0)
			odd++;
	if(odd!=0&&odd!=2)
		printf("Impossible\n");
	else{
		int trees = 0 ;
		for(int i=1;i<colors;i++)
			if(pa[i]==i)
				trees ++;
		if(trees>1)
			printf("Impossible\n");
		else
			printf("Possible\n");		
	}
	return 0;
}


