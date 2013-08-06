/**
矩形覆盖，求面积问题，其中线段树的构建和update流程需要注意，和之前所作的不一样。
http://www.cnblogs.com/kuangbin/archive/2011/08/16/2140544.html
AC：
	8764552	2013-07-30 14:47:26	Accepted	1542	0MS	344K	2486 B	G++	momoliu
*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAXL 201
using namespace std;

typedef struct Line
{
	double y1,y2,x;
	int flag;//1--出度，-1--入度
}Line;
Line lines[MAXL*2];
typedef struct Node{
	double h,l;
	int hLoc,lLoc;
	double length; //记录区间的长度
	int flag;//标记当前区间的长度来源：由入度line决定，还是由子节点决定
}Node;

Node nodes[4*MAXL];
double y[MAXL*2];

bool cmp(Line a,Line b){
	return a.x<b.x;
}
void calLen(int idx){
	if(nodes[idx].flag>0){
		nodes[idx].length = nodes[idx].h-nodes[idx].l;
		return;
	}
	//point!!!!!!!!!!!
	if(nodes[idx].hLoc==nodes[idx].lLoc+1) 
		nodes[idx].length = 0 ;
	else
		nodes[idx].length = nodes[idx<<1].length+nodes[idx<<1|1].length;
}

void update(int idx,Line e){
	if(nodes[idx].h==e.y2 && nodes[idx].l == e.y1){
		nodes[idx].flag += e.flag;
		calLen(idx);
		return;
	}
	//point!!!!!
	if(e.y2<=nodes[idx<<1].h)
		update(idx<<1,e);
	else if(e.y1>=nodes[idx<<1|1].l)
		update(idx<<1|1,e);
	else
	{
		Line tmp = e;
		tmp.y2 = nodes[idx<<1].h;
		update(idx<<1,tmp);
		tmp = e;
		tmp.y1 = nodes[idx<<1|1].l;
		update(idx<<1|1,tmp);
	}
	calLen(idx);
}
/*
在建树过程中，利用的是端点进行建树，而不是区间来建树。
*/
void build(int lIdx,int rIdx,int idx){
	nodes[idx].h = y[rIdx];
	nodes[idx].l = y[lIdx];
	//point
	nodes[idx].hLoc = rIdx;
	nodes[idx].lLoc = lIdx;
	nodes[idx].length = nodes[idx].flag = 0;
	if(lIdx+1 == rIdx) return;
	int mid = (lIdx+rIdx)>>1;
	build(lIdx,mid,idx<<1);
	build(mid,rIdx,idx<<1|1);	
}
int main(){
	int cases =1 ,n;
	freopen("1511.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
		int t = 1;
		for(int i = 1; i <=n;i++){
			double x1,y1,x2,y2;
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			lines[t].y1 = y1; //smaller y
			lines[t].y2 = y2;//bigger y
			lines[t].x = x1;
			lines[t].flag = 1;
			y[t] = y1;
			t++;
			lines[t].y1 = y1; 
			lines[t].y2 = y2;
			lines[t].x = x2;
			lines[t].flag = -1;
			y[t] = y2;
			t++;
		}
		sort(y+1,y+t);
		sort(lines+1,lines+t,cmp);
		build(1,t-1,1);
		update(1,lines[1]);
		double reg = 0;
		for(int i=2 ;i<t;i++){
			reg += nodes[1].length*(lines[i].x-lines[i-1].x);
			update(1,lines[i]);
		}
		
		printf("Test case #%d\nTotal explored area: %.2f\n\n",cases++,reg);
	}

	return 0;
}
