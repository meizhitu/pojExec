/*
树状数组，输入n对（x,y)求出每对x,y输入时，前面的数字中<=x，<=y的pair个数。因为y是增序输入，所以可以忽略y只关注x。
树状数组的底层数组含义为：长度为maxV的数组，输入pair(x,y)时，在array[x]处加1.
判断每个star的level就是求出array[1]到array[x+1]的和（因为x可以为0，所以在更新时应该更新x+1);
*/
//这道题也可以用线段树解决。
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define maxV 32010
int ans[maxV]; //对应数组c
int arr[maxV];
int lowBit(int idx)
{
	return idx&(-idx);
}
void update(int idx,int n){
	while(idx<=maxV){
		ans[idx]++;
		idx += lowBit(idx);
	}
}
int getSum(int idx){
	int sum =  0;
	while(idx>0){
		sum += ans[idx];
		idx -= lowBit(idx);
	}
	return sum;
}
int main(){
	int n ;
	freopen("2352.txt","r",stdin);
	scanf("%d",&n);
	memset(ans,0,sizeof(ans));
	for(int i = 1;i<=n;i++)
	{
		int y,x;
		scanf("%d%d",&x,&y);
		//求出底层数组1到x+1的和即为level。
		int level = getSum(x+1);
		arr[level]++;
		update(x+1,n);
	}
	for(int i = 0;i<n;i++)
		printf("%d\n",arr[i]);
	return 0;
}
