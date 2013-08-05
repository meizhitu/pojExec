#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;
#define MAXN 520000
typedef struct Node{
	int l,r;
	int contr;
}Node;
Node nodes[MAXN*4];
char names[MAXN][20]; 
int values[MAXN];
int RPrime[]=
{//反素数
    1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,
    20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,
    554400
};
int fact[]=
{//反素数约数个数
    1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,
    144,160,168,180,192,200,216
};

void build(int l,int r,int idx){
	nodes[idx].l = l;
	nodes[idx].r = r;
	nodes[idx].contr = r-l+1;
	if(l==r) return;
	int mid = (l+r)>>1;
	build(l,mid,2*idx);
	build(mid+1,r,2*idx+1);
}
int query(int idx,int pos){
	nodes[idx].contr--;
	if(nodes[idx].l == nodes[idx].r){
		return nodes[idx].l;
	}
	if(pos<=nodes[idx*2].contr)  
		query(2*idx,pos);
	else  
		query(2*idx+1,pos-nodes[2*idx].contr);
}
int main(){
	int n,k;
	freopen("2886.txt","r",stdin);
	
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		build(1,n,1);
		int p;
		int maxx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s %d", &names[i], &values[i]);
		}
		int i=0;
		while(1)
		{
			if(RPrime[i]>n)
			{
				p=RPrime[i-1];
				maxx= fact[i-1];
				break;
			}
			i++;
		}
		int indx;
		for(int i=0;i<p;i++)
		{
			n--;
			indx=query(1,k);
			if(n==0)break;
			if(values[indx]>0)
				k=(k-1+values[indx]-1)%n+1;
			else
				k=((k-1+values[indx])%n+n)%n+1;
		}
		cout<<names[indx]<<' '<<maxx<<endl;
	}
	
	return 0;
}