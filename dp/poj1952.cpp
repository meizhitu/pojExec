/*
“逢低吸纳”是炒股的一条成功秘诀。如果你想成为一个成功的投资者,就要遵守这条秘诀: "逢低吸纳,越低越买" 这句话的意思是:每次你购买股票时的股价一定要比你上次购买时的股价低.按照这个规则购买股票的
次数越多越好,看看你最多能按这个规则买几次。
给定连续的 N 天中每天的股价。你可以在任何一天购买一次股票,但是购买时的股价一定要比你上次
购买时的股价低。写一个程序,求出最多能买几次股票。

*/
#include <iostream>
#include <string.h>
using namespace std;
const int size = 5100;
int maxlen[size];//记录当前第1个点到第i个点之间的最长下降序列长度
int maxnum[size];//记录1~i之间的最长下降序列个数 
int main()
{
    int a[size];
    int n;
    while (scanf("%d", &n) != EOF){
          for (int i = 1; i <= n; i ++){
              scanf("%d", &a[i]); 
              maxnum[i] = 0;
              maxlen[i] = 1;  
          }      
          for (int i = 1 ; i <= n; i ++){
              for (int j = 1; j < i; j ++){
                  if (a[i] < a[j]){
                     maxlen[i] = max(maxlen[i], maxlen[j]+1);         
                  }
              }    
          }
          for (int i = 1; i <= n; i ++)
              if (maxlen[i] == 1)maxnum[i] = 1;
          for (int i = 2; i <= n; i ++){
              for (int j = i-1; j > 0; j --){
                  if (a[j] > a[i]){
					  //必须要有，迭代的进行贡献
                     if (maxlen[j]+1 == maxlen[i]){
                        maxnum[i] += maxnum[j];                
                     }    
                  }
                  if (a[j] == a[i]){//此处如果不赋值为0的话，130 130 150 160 在150的时候，将利用2个130
                     if (maxlen[i] == 1)maxnum[i] = 0;//如果搜索到一个相同的数后仍没有找到符合要求的序列，则为了避免重复赋值为0 
                     break;         
                  }
              }    
          }
          int maxx = -1;
          for (int i = 1; i <= n; i ++){
              if (maxlen[i] > maxx)  maxx = maxlen[i];    
          }
          int ans = 0;
          for (int i = 1; i <= n; i ++){
              if (maxlen[i] == maxx) ans += maxnum[i] ;    
          }
          printf("%d %d\n", maxx, ans);
    }
    return 0;    
}