
#include<stdlib.h>
#include<stdio.h>
#define MAXSENTENCES 100010
#define MAXNUMBERS 50010
int f[MAXNUMBERS];
int rank[MAXNUMBERS];
/*
并查集结构，但需要注意染色问题：确定父子节点的相对关系

*/
int find(int x){
	if(x==f[x]) return x;
	int t = find(f[x]); 
	rank[x] = (rank[x]+rank[f[x]])%3;
	f[x] = t;
	return t;
}
int join(int x, int y, int D){
	int fx = find(x);
	int fy = find(y);
	if(fx==fy)
		return (rank[x]-rank[y]+3)%3 == D;
	f[fx] = fy;
	rank[fx] =(rank[y]-rank[x]+3+D)%3;  
	return 1;
}
int main(){
	int num,k;
	scanf("%d%d",&num,&k);
	int i;
	for( i = 1;i<=num;i++){
		f[i] = i;
		rank[i] = 0;
	}
	int error = 0 ;
	for( i = 0 ;i<k;i++){
		int D,x,y;
		scanf("%d%d%d",&D,&x,&y);
		if(x>num || y>num) error++;
		else if(D==2 && (x==y)) error++;
		else if(join(x,y,D-1) == 0) error++;
	}
	printf("%d\n",error);
	return 0;
}
