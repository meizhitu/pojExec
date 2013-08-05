/*
　怎么才能找到最少的步数呢？我想了半天也没怎么想出来，于是看了看DISCUSS，总结以下：

　　遍历整个磁盘，设i为当前遍历的簇的编号，clusters为整个磁盘，clusters[i]表示第i个簇是否被占用，被哪个编号的文件片段占据。

　　(1) 如果clusters[i]为0，也就是未被使用，不进行处理。

　　(2) 如果clusters[i]为i，也就是已经到了整理好的状态，不进行处理。

　　(3) 如果clusters[i]不满足1和2，则又有两种情况。

　　　　情况一：磁盘使用情况成链：如图所示：

　　　　簇号：　　1  2  3  4  5  6 ... 　　　　

　　　　逻辑编号：5  0  4  2  3  0 ...

　　　　第1个簇被第5个文件片断占据，第5个簇又被第3个文件片段占据，第3个簇又被第4个文件片段占据，第4个簇又

　　　　被第2个文件片断占据，第2个簇未被占据。算法就很简单了，按照簇被访问的反方向：

　　　　clusters[2] = clusters[4]，clusters[4] = clusters[3]，clusters[3] = clusters[5]，

　　　　clusters[5] = clusters[1]，最后clusters[1] = 0。怎么样反方向呢，使用一个栈就好了。

　　　　

　　　　情况二：磁盘使用情况成环：如图所示：

　　　　簇号：　　1  2  3  4  5  6 ... 　　　　

　　　　逻辑编号：5  1  4  2  3  0 ...

　　　　这种情况跟情况一差不多，只是最后clusters[2]指向了第1个簇，这样就形成了一个环，这里只是需要额外的

　　　　处理一下，就像交换2个变量一样，先在从磁盘末尾找到1个空的簇，因为题目保证至少有一个空的簇，先把　　　　

　　　　clusters[2]放到这个空的簇中，然后再执行情况1中的操作，最后再把空的簇的值赋给clusters[1]就好了。

*/
#include <cstdio>
#include <stack>
#include <stdio.h>
#include <string.h>
using std::stack;

int clusters[10001];        //簇的使用情况
int cluster_num, file_num;  //簇的总数和文件个数
int counter = 1;            //文件片段起始编号
int mov_num = 0;            //操作总数
stack<int> s;
int findLastEmpty(){
	for(int j=cluster_num;j>0;j--){
		if(clusters[j]==0) return j;
	}
}

void solve( ){
	for(int i = 1;i<=cluster_num;i++){
		if(clusters[i] == i ||clusters[i]==0) continue;
		bool isCircle = false;
		int next = clusters[i];
		s.push(i);
		while(true){
			if(clusters[next] == i ){
				isCircle = true;break;
			}else if(clusters[next] == 0){
				isCircle =false;break;
			}
			s.push(next);
			next = clusters[next];
		}
		if(isCircle){
			int lastEmpty = findLastEmpty();
			printf("%d %d\n",next,lastEmpty);
			clusters[lastEmpty] = clusters[next];
			/*
			注意环境清理
			*/
			clusters[next] = 0;
			while(!s.empty()){
				int t = s.top();
				printf("%d %d\n",t,next);
				mov_num++;
				clusters[next] = clusters[t];
				next = t;
				s.pop();
			}
			clusters[next] = clusters[lastEmpty];
			printf("%d %d\n",lastEmpty,next);
			
			clusters[lastEmpty] = 0 ;
		}
		else{
			while(!s.empty()){
				int t = s.top();
				mov_num++;
				printf("%d %d\n",t,next);
				s.pop();
				/*
				注意环境清理
				*/
				clusters[next] = clusters[t];
				next = t ;
			}
			clusters[next] = 0 ;
		}
	}
	if(mov_num == 0)
		printf("No optimization needed\n");

}
int main(){
	int n,m;
	freopen("1033.txt","r",stdin);
	scanf("%d%d",&cluster_num,&m);
	memset(clusters,0,sizeof(clusters));
	
	for(int i = 0 ;i<m;i++){
		int k ;
		scanf("%d",&k);
		int lc;
		for(int j = 0 ;j<k;j++){
			scanf("%d",&lc);
			clusters[lc] = counter++; //记录了目标位置
		}
	}
	solve();
	return 0;
}