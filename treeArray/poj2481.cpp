#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
using namespace std;
#define maxN 100010
int c[maxN];
int ret[maxN];
typedef struct NODE{
	int x,y;
	int idx;
}Node;
Node in[maxN];
bool cmp(Node a,Node b){
	if(a.y==b.y) return a.x<b.x;
	return a.y > b.y;
}
int lowBit(int x){
	return x&(-x);
}
void update(int idx){
	while(idx<maxN){
		c[idx]++;
		idx+= lowBit(idx);
	}
}
int sum(int idx){
	int ret = 0 ;
	while(idx>0){
		ret += c[idx];
		idx -= lowBit(idx);
	}
	return ret;
}
int main(){
	int n;
	freopen("2481.txt","r",stdin);
	while(scanf("%d",&n)&&n){
		for(int i = 1;i<=n;i++){
			int x,y;
			scanf("%d%d",&in[i].x,&in[i].y);
			in[i].x++; //range的范围从0开始，底层的数组坐标应该从1开始。
			in[i].y++;
			in[i].idx = i;
		}
		memset(c,0,sizeof(c));
		sort(in+1,in+n+1,cmp);
		Node *pre = 0 ;
		for(int i = 1; i<=n;i++){
			int t1 = sum(in[i].x);
			if(pre && pre->x == in[i].x && pre->y==in[i].y)
				ret[in[i].idx] = ret[in[i-1].idx];
			else 
				ret[in[i].idx] = t1;
			update(in[i].x);
			pre = &in[i];
		}
		for(int i = 1;i<=n;i++)
			printf("%d ",ret[i]);
		printf("\n");
	}
	return 0;
}