//矩形的面积计算
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

#define MAXL 2010
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
bool isSep(int x1,int x2,int x3,int x4){
	if(x1==-1 && x2==-1 && x3==-1 && x4==-1)
		return true;
	return false;
}
int t =1;
void add(int x1,int y1,int x2,int y2){
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
void compute(){
	sort(y+1,y+t);
	sort(lines+1,lines+t,cmp);
	int cnt = t ;
	t = unique(y+1,y+cnt)-y;
	build(1,t-1,1);
	update(1,lines[1]);
	int reg = 0;
	for(int i=2 ;i<cnt;i++){
		reg += nodes[1].length*(lines[i].x-lines[i-1].x);
		update(1,lines[i]);
	}
	printf("%d\n",reg);
}
void init(){
	t = 1;
	memset(lines,0,sizeof(lines));
	memset(y,0,sizeof(y));
	memset(nodes,0,sizeof(nodes));
}
int main(){
	int cases =1 ,n;
	int x1,y1,x2,y2;
	bool prev = false;
	bool sep =false;
	init();
	freopen("1389.txt","r",stdin);
	while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)!=EOF){
		sep =isSep(x1,y1,x2,y2); 
		if(prev && sep){
			 break;
		 }
		 prev = sep;
		 if(sep) {
			 compute();
			 init();
			 continue;
		 }
		 else{
			 add(x1,y1,x2,y2);
		 }
		
	}

	return 0;
}
