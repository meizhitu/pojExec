#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#define MAXP 1000010
using namespace std;
queue<int> q;
int mov[MAXP];
bool visited[MAXP];

void setMov(int i,int v){
	if(mov[i]>v || mov[i]==-1)
		mov[i]=v;
}
void bfs(int n,int k){
	mov[n] = 0;
	
	if(n==k){
	//	mov[n] = 0;
		return;
	}
	q.push(n);
	while(!q.empty()){
		int t = q.front();
		
		q.pop();
		if(t==k) return;
		if(!visited[t]){
			q.push(t+1);
			if(t>0){
				q.push(t-1);
				setMov(t-1,mov[t]+1);
			}
			/*
			若此处让其无限扩展，数组将溢出。
			*/
			if(t<k){
				q.push(t*2);
				setMov(t*2,mov[t]+1);
				
			}
			setMov(t+1,mov[t]+1);
		
		}
		visited[t] = true;
	}
}

int main(){
	int n,k;
	freopen("3278.txt","r",stdin);
	memset(visited,false,sizeof(visited));
	memset(mov,-1,sizeof(mov));
	
	scanf("%d%d",&n,&k);
	bfs(n,k);
	printf("%d\n",mov[k]);
	return 0;
}