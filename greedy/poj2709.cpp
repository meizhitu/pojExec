#include <iostream>
#include <cstring>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#define MAXN 13
#define MAXGREY 1010
using namespace std;
int ml[MAXN];
bool cmp(int a, int b)
{
	return a>b;
}
int computeGrey(int n,int *max){
	
	sort(ml,ml+n,cmp);
	if(ml[3-1] == 0){
		(*max) ++;
		for(int i = 0 ;i<n;i++)
			ml[i] = ml[i]+50;
		
	}
	/*
	!!!!!每次只能减去1ml 原因如下：
		一次如果不只减1：
		排序： 3 3 3 3
		减3： 3 0 0 0
		不能再减了

		实际上：3 3 3 3
		减->  3 2 2 2
		排序->  2 2 2 3
		减->  2 1 1 2
		排序->  1 1 2 2
		减->  1 0 1 1
		排序->  0 1 1 1
		减->  0 0 0 0
		最多可以减4次
	
	*/
	
	int grey = 1;
	ml[0] -= grey;
	ml[1] -= grey;
	ml[2] -= grey;
	return grey;
	
}
int cal(int grey,int n){
	sort(ml,ml+n,cmp);
	if(grey == 0)
		return ceil(ml[0]/50.0);
	int max = ceil(ml[0]/50.0);
	for(int i = 0 ;i<n;i++)
		ml[i] = max*50-ml[i];
	
	while(grey > 0 ){
		grey -= computeGrey(n,&max);
	}
	return max;
}
int main(){
	int n,grey;
	freopen("2709.txt","r",stdin);
	while(scanf("%d",&n)){
		if(n==0) break;
		memset(ml,0,sizeof(ml));
		for(int i = 0 ;i<n;i++)
			scanf("%d",&ml[i]);
		scanf("%d",&grey);
		printf("%d\n",cal(grey,n));
	}
	return 0;
}

