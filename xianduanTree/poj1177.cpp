/*矩形周长求并级 经典*/
#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAXL 10010
using namespace std;

typedef struct Line
{
	int y1,y2,x;
	int flag;//1--出度，-1--入度
}Line;
Line lines[MAXL*2];
typedef struct Node{
	int h,l;
	int hLoc,lLoc;
	int nums;//区间分段数,[1,2][4,5]为两个区间，而[1,2],[2,3]为一个区间
	int rb; //右端点覆盖情况
	int lb;//左端点覆盖情况
	int length; //记录区间的长度
	int flag;//标记当前区间的长度来源：由入度line决定，还是由子节点决定
}Node;

Node nodes[4*MAXL];
int y[MAXL*2];

bool cmp(Line a,Line b){
	if( a.x == b.x ) return a.flag > b.flag;
	return a.x < b.x;
}
void calLen(int idx){
	if(nodes[idx].flag>0){
		nodes[idx].length = nodes[idx].h-nodes[idx].l;
		nodes[idx].nums=nodes[idx].lb=nodes[idx].rb=1;
		return;
	}
	//point!!!!!!!!!!!
	if(nodes[idx].hLoc==nodes[idx].lLoc+1) 
		nodes[idx].nums=nodes[idx].lb=nodes[idx].rb=nodes[idx].length = 0 ;
	else{
		nodes[idx].length = nodes[idx<<1].length+nodes[idx<<1|1].length;
		nodes[idx].rb = nodes[idx<<1|1].rb;
		nodes[idx].lb= nodes[idx<<1].lb;
		//个人感觉nums是这道题区别与面积计算的关键。
		nodes[idx].nums=nodes[idx<<1].nums+nodes[idx<<1|1].nums-nodes[idx<<1].rb*nodes[idx<<1|1].lb;
	}
}

void update(int idx,Line e){
	if(nodes[idx].h==e.y2 && nodes[idx].l == e.y1){
		nodes[idx].flag += e.flag;
		calLen(idx);
		return;
	}
	if( nodes[idx].lLoc == nodes[idx].hLoc - 1 ) return ;
	
	//point!!!!!
	//int mid = (nodes[idx].h+nodes[idx].l)>>1;
	//	int mid = nodes[idx<<1].h;
	int mid = (nodes[idx].lLoc+nodes[idx].hLoc)>>1;
	mid = y[mid];
	
	if(e.y2<=mid)
		update(idx<<1,e);
	else if(e.y1>=mid)
		update(idx<<1|1,e);
	else
	{		 
		Line tmp =e ;
		tmp.y2= mid;
		update(idx<<1,tmp);
		tmp = e;
		tmp.y1=mid;
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
	nodes[idx].rb=nodes[idx].lb=nodes[idx].nums= 0;
	if(lIdx+1 == rIdx) return;
	int mid = (lIdx+rIdx)>>1;
	build(lIdx,mid,idx<<1);
	build(mid,rIdx,idx<<1|1);	
}
int main(){
	int cases =1 ,n;
	freopen("1177.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		//!!!!!!point specail situation.
		if( n == 0 )
		{
			printf("0\n");
			continue;
		} 
		int t = 1;
		for(int i = 1; i <=n;i++){
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
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
		int cnt = t ;
		//必须处理下y，重复的节点会导致update出问题。
		t= unique(y+1,y+cnt) -(y);
		build(1,t-1,1);
		int ans = 0,last = 0,numbers = 0;
		for(int i=1; i<cnt; i++)
		{
		
			update(1,lines[i]);
			if( i > 1 )
				ans += 2 * numbers * (lines[i].x - lines[i-1].x);//计算平行于x轴的长度 
			ans += abs(nodes[1].length - last);		   // 计算平行于y轴的长度
			last = nodes[1].length; 
			numbers = nodes[1].nums;
		}	
		printf("%d\n",ans);
	}
	return 0;
}
