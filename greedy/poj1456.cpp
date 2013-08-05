//其实是贪心,超市售货计划:每天只能卖一种商品。如果使用dp，复杂度太高O(n^3),因而使用贪心。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXN 10010
using namespace std;
bool visited[MAXN];
int pa[MAXN];
typedef struct product{
	int price;
	int deadline;
}Product;
Product prods[MAXN];
bool cmp(Product a,Product b){
	return a.price > b.price;
}
int solve(int n ){
	int maxProfits = 0 ;
	for(int i= 1;i<=n;i++){
		int j = prods[i].deadline;
		while(j>=1 && visited[j]) j--;
		if(j>=1)
		{ 
			visited[j] = true;
			maxProfits += prods[i].price;
		}
	}
	return maxProfits;
}
int find(int x){
	if(x==pa[x]) return x;
	int t = find(pa[x]);
	pa[x] = t;
	return t;
}
int solve1(int n ){
	int maxProfits = 0 ;
	for(int i= 1;i<=n;i++){
		int ava = find(prods[i].deadline);
		if(ava == 0) continue;
		maxProfits += prods[i].price;
		int next = find(ava-1);
		pa[ava] = next;
	}
	return maxProfits;
}
int main(){
	int n;
	freopen("1456.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		memset(visited,false,sizeof(visited));
		for(int i =0;i<MAXN;i++)
			pa[i] = i;
		for(int i= 1;i<=n;i++)
			scanf("%d%d",&prods[i].price,&prods[i].deadline);
		sort(prods+1,prods+n+1,cmp);
		printf("%d\n",solve1(n));
	}
	return 0;
}

