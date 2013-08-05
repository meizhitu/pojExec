/*【题解】：不得不说，这道题出得非常好，特别是uva那里的大数据（poj的数据太水了），对于剪枝能力要求很高。下面说下几个重要的剪枝：
1.把所有木棍的长度从大到小排列，组合木棒时优先使用长的木棍，这样可以加快组合速度，并且对后面的剪枝有帮助。
2.木棒的长度一定是大于等于最长木棍的长度并且小于等于所有木棍长度的和，这个很容易证明。
3.木棒的长度一定是所有木棍长度的和的约数，这个也很容易证明。
4.在某一个木棒的组合过程中，对于当前的木棍stick[i]，如果stick[i-1]没有被组合并且stick[i] == stick[i-1]，
那么不用考虑stick[i]，显然stick[i]最终也不会被组合。
5.如果此次是在尝试第i个木棒的第一段，假设stick[j]为当前可以被使用的最长的木棍，
如果此次组合失败，直接退出搜索，即退回到对第i-1个木棒的搜索。试想：失败说明现在使用stick[j]是不可行的，
那么以后无论什么时候使用stick[j]都是不可行的，因为以后再处理stick[j]时可使用的木棍一定是当前可使用的木棍的子集，
	在更多木棍选择的情况下都不能组合成功，那么，在更少木棍选择的情况下一定不能组合成功。
									*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <algorithm>
#define MAXS 70
using namespace std;
int sticks[MAXS];
int average;
int sum;
int num;
int visited[MAXS];
bool cmp(int a,int b){
	return a>b;
}
bool DFS(int current,int index,int count){
	if(average*count == sum) return true;
	
	for(int i = index;i<num;i++){
		if(visited[i]||(i&&!visited[i-1]&&(sticks[i-1]==sticks[i]))) continue;
		if(current+sticks[i]==average){
			visited[i] = true;
			if(DFS(0,0,count+1)) return true;
			visited[i] = false;
			return false;
		}
		else if(current+sticks[i] < average){
			visited[i]=true;
			if(DFS(current+sticks[i],i+1,count)) return true;
			visited[i] = false;
		}
		if(current==0) return false;
	}
	return false;
}
int solve(int n,int sum){
	sort(sticks,sticks+n,cmp);
	for(average=sticks[0];average<sum;average++){
		if(sum % average != 0 ) continue;
		memset(visited,false,sizeof(visited));
		if(DFS(0,0,0)) return average;
	}
	return sum;
}

int main(){
	freopen("1011.txt","r",stdin);
	while(scanf("%d",&num)){
		if(num == 0) break;
		memset(sticks,0,sizeof(sticks));
		sum = 0 ;
		for(int i = 0 ;i<num;i++){
			scanf("%d",&sticks[i]);
			sum += sticks[i];
		}
		printf("%d\n",solve(num,sum));
	}
	return 0;
}