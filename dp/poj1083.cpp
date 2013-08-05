/*
为区间的每个走廊增加计数器
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 205
int used[MAXN];
int format(int s){
	if(s%2 == 0 )return s/2;
	return (s+1)/2;
}
int main(){
	int cases;
	freopen("1083.txt","r",stdin);
	scanf("%d",&cases);
	while(cases--){
		int m,from,to ;
		memset(used,0,sizeof(used));
		scanf("%d",&m);
		for(int i = 1;i<=m;i++){
			int s,t;
			scanf("%d%d",&s,&t);
			if(s>t){
				int tmp = s;
				s = t;t=tmp;
			}
			from = format(s);
			to = format(t);
			for(int j= from;j<=to;j++)
				used[j]++;
		}
		int max = -1;
		for(int i = 1;i<MAXN;i++){
			if(max < used[i])
				max = used[i];
		}
		printf("%d\n",max*10);
	}
	return 0;
}