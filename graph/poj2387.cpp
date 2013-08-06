//dijkstra和SPFA的算法练习。
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

#define inf 1<<30
#define MAXV 1010
#define MAXE 2010

using namespace std;
vector< pair<int,int> > nodes[MAXV];
int dis[MAXV];
bool inQ[MAXV];
bool used[MAXV];//for dijkstra
int n ;
int Dijkstra(){
	memset(used,false,sizeof(used));
	dis[1] = 0;
	
	vector<pair<int,int> > node;
	vector<pair<int,int> >::iterator it;
	
	
	for(int j = 1;j<=n;j++){
		int min = inf;
		int minLoc = 0 ;
		for(int i = 1;i<=n;i++){
			if(!used[i] && dis[i]!=inf && min > dis[i]){
				min = dis[i];
				minLoc = i;
			}
		}
		used[minLoc] = true;
		//printf("min=%d\n",minLoc);
		//modify
		for(it=nodes[minLoc].begin();it!=nodes[minLoc].end();it++){
			if(dis[it->first]>(it->second+dis[minLoc]))
				dis[it->first] = it->second+dis[minLoc];
		}
	}
	return dis[n];
}
int SPFA(){
	queue<int> q;
	q.push(1);
	inQ[1] = true;
	dis[1] = 0;
	vector<pair<int,int> > node;
	vector<pair<int,int> >::iterator it;
	while(!q.empty()){
		int id = q.front();
		node = nodes[id];
		q.pop();
		inQ[id] = false;
		for(it = node.begin();it!=node.end();it++){
			if(dis[it->first] > dis[id]+it->second){
				dis[it->first] = dis[id]+it->second;
				if(!inQ[it->first]){
					q.push(it->first);
					inQ[it->first] = true;
				}
			}
		}

	}
	return dis[n];
}
int solve(){
	//return SPFA();
	return Dijkstra();
}
int main(){
	int t;
	freopen("2387.txt","r",stdin);
	scanf("%d%d",&t,&n);
	memset(inQ,false,sizeof(inQ));
	for(int i =0;i<=n;i++)
		dis[i] = inf;
	for(int i = 1;i<=t;i++){
		int s,e,w;
		scanf("%d%d%d",&s,&e,&w);
		nodes[s].push_back(make_pair<int,int>(e,w));
		nodes[e].push_back(make_pair<int,int>(s,w));
	}
	printf("%d\n",solve());
}
