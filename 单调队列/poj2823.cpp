//单调数组比先断树要有节操一些
//11943373	sdutacm1	2965	Running & Judging			G++	1467B	2013-08-08 14:50:21#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define MAXN 1000010
int data[MAXN];
int minQ[MAXN];
int maxQ[MAXN];
int n,k;

void minQueue(){
	int h =1,p = 0 ;
	minQ[1] = 1;
	for(int i = 1;i<=n;i++)
	{
		if(i-minQ[h]==k)
			h++; //window size
		if(p==h-1 || data[i] > data[minQ[p]])
			minQ[++p] = i;
		else
		{
			while(p>=h && data[i]<=data[minQ[p]]){
				//printf("挤出%d\n",p);
				minQ[p] = i;
				p --;
			}
			p++;
			//printf("挤出后 p=%d\n",p);
		}
		if(i>=k)
			printf("%d ",data[minQ[h]]);
	}
}
void maxQueue(){
	int h =1,p = 0 ;
	maxQ[1] =1;
	for(int i = 1;i<=n;i++){
		if(i-maxQ[h] == k)
			h++;
		if(p == h-1 || data[i]<data[maxQ[p]])
			maxQ[++p] = i;
		else {
			while(p>=h && data[i]>=data[maxQ[p]]){
				maxQ[p] = i;
				p --;
			}
			p++;
		}
		if(i>=k)
			printf("%d ",data[maxQ[h]]);
	}

}
int main(){
	freopen("2823.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i = 1;i<=n;i++)
		scanf("%d",&data[i]);
	minQueue();
	printf("\n");
	maxQueue();
}
