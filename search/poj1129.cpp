#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#define MAXREAPTER 30
using namespace std;
typedef struct Point{
	int data;
	int nextPoints[MAXREAPTER];
	int nums;
	bool visited;
	int color;
}Point;
Point nodes[MAXREAPTER];
int color ;
int colors[MAXREAPTER];


Point* getNode(Point* node,int idx){
	return  &nodes[node->nextPoints[idx]];
}
bool existsColor(Point* node,int c){
	for(int i=0;i<node->nums;i++)
		if(getNode(node,i)->color == c) return false;
	return true;
}
void DFS(Point * node){
	node->visited = true;
	
	for(int i = 0; i < node->nums;i++){
		Point * p = getNode(node,i);
		
		if(!p->visited){
			
			p->visited = true;
			int j;
			for( j = 1; j<= color;j++){
				if(existsColor(p,colors[j]))
				{
					p->color = colors[j];
					break;
				}
			}
			if(j==color+1)
			{
				p->color = ++color;
				colors[color] = color;
			}
			/*四色定理:
			如果在平面上划出一些邻接的有限区域，那么可以用四种颜色来给这些区域染色，
				使得每两个邻接区域染的颜色都不一样；
			*/
			if(color==4) break;
			DFS(p);
		}
	}
}
int DFSVisit(int n){
	nodes[0].color = 1;
	for(int i=0;i<n;i++){
		if(!nodes[i].visited){
			DFS(&nodes[i]);
		
		}
	}

}
int main(){
	int n;
	freopen("1129.txt","r",stdin);
	while(scanf("%d",&n)){
		//	printf("%d\n",n);
		if(n==0) break;
		color = 1;
		memset(colors,0,sizeof(colors));
		colors[1]=1;
		//	Point * nodes = new Point[n+1];
		memset(nodes,0,sizeof(nodes));
		for(int i = 0 ;i< n;i++){
			char chars[100];
			bool sep = false;
			int k =0;
			
			scanf("%s",chars);
			
			for(int l=0;chars[l];l++){
				char ch = chars[l];
				if(ch==':') sep = true;
				else if(ch>='A' && ch <='Z' && !sep){
					nodes[i].visited = false;
					nodes[i].color = 0 ;
					nodes[i].nums = 0; 
					nodes[i].data = ch-'A';
				}
				else if(sep){
					nodes[i].nextPoints[k++] = ch-'A'; 
					nodes[i].nums = k;
				}
			}
		}
		DFSVisit(n);
		if(color == 1)
			printf("1 channel needed.\n");
		else
			printf("%d channels needed.\n",color);
			
	}
	return 0;
}