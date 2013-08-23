/*这道题好神奇啊

更新一个区域(x1,y1)到(x2,y2),借鉴http://blog.csdn.net/zxy_snow/article/details/6264135所绘画的图形，从(0,0)到(x,y)的求和是很容易的，sum(x,y)是基于c[i][j]的，多个c[i][j]组成一个sum。c[i][j]表示arr[i-2^k+1][j-2^m+1]到arr[i][j]这个区间内每个点都翻转n次。
*/
#include <cstdio>
#include <cstring>
int a[1001][1001],n,m,k,x,t,a1,a2,a3,a4;
char c;
inline int lowbit(int x){
	return x&(-x);
}
int get(int x,int y){
	int ret=0;
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			ret=(ret+a[i][j])%2;
	return ret;
}
void change(int x,int y){
	printf("x,y=%d,%d\n",x,y);
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j)){
			a[i][j]=(a[i][j]+1)%2;
		}
}
int main(){
      //freopen("2155.txt","r",stdin);
	scanf("%d",&x);
	while(x--){
		scanf("%d%d",&n,&t);
		getchar();
		memset(a,0,sizeof(a));
		for(int i=0;i<t;++i){
			scanf("%c",&c);
			if(c=='C'){
				scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
				change(a3,a4);
				change(a1-1,a2-1);
				change(a1-1,a4);
				change(a3,a2-1);
			}else{
				scanf("%d%d",&a1,&a2);
				printf("%d\n",get(a1,a2));
			}
			getchar();
		}
		printf("\n");
	}
	return 0;
}