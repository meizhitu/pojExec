#include <iostream>
#include <math.h>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
vector<int>hash[10001];//用vector代替邻接表

#define MAXN   10001
#define mmin(seq, a, b)  ((seq[a] < seq[b]) ? (a) : (b))
int indegree[MAXN];
/**///// DP status
int fij[100000][100];//fij表示区间a[i]到a[i+2^j-1]上最小值的下标。

template <typename T>
void st(T seq[], int n)//预处理
{ 
    memset(fij, 0, 100 * MAXN * sizeof(int));
    int k = (int)(log((double)n) / log(2.0)); 
    /**/////初始状态
    for(int i = 0; i < n; i++)
        fij[i][0] = i; 
    /**/////递推计算状态
    for(int j = 1; j <= k; j++)
    {
        for(int i = 0; i + (1 << j) - 1 < n; i++)
        {
            //
            int m = i + (1 << (j - 1)); 
            fij[i][j] = mmin(seq, fij[i][j - 1], fij[m][j - 1]);
        }
    }
}
template <typename T>
int RMQ(T seq[], int i, int j)//求解RMQ,返回值为seq[i]到seq[j]区间内最小值的下标。
{
    /**///// 用对2去对数的方法求出k
    int k = (int)(log(double(j - i + 1)) / log(2.0)); 
    int t = mmin(seq, fij[i][k], fij[j - (1 << k) + 1][k]);
    return t;
}

int E[MAXN*2+1];
int R[MAXN*2+1]; //R[i]表示节点i第一次出现在E中的下标。
int D[MAXN*2+1];
int p=0;
void dfs(int r,int deep)//深搜，算出E,R,D数组
{
    p++;
    E[p]=r;
    D[p]=deep;
    R[r]=p;
    int i;
    int size=hash[r].size();
    for(i=0;i<size;i++)
    {

        dfs(hash[r][i],deep+1);
        p++;
        E[p]=r;
        D[p]=deep;
    }
    
}

int main()
{

    int testcase;
    int n;
    int i,j;
    int s,t;
    scanf("%d",&testcase);
    for(i=1;i<=testcase;i++)
    {
    
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            indegree[j]=0;
            hash[j].clear();
        }
        p=0;
        for(j=1;j<n;j++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            hash[a].push_back(b);//a的孩子节点链表
            indegree[b]++;
        }
        scanf("%d%d",&s,&t);
        int root;
        for(j=1;j<=n;j++)
        {

            if(indegree[j]==0) //寻找root
            {
                root=j;
                break;
            }
        }
        dfs(root,0);//root=8
        st(D,2*n+2);
        if(R[s]<R[t])
            printf("%d\n",E[RMQ(D,R[s],R[t]) ] );
        else
            printf("%d\n",E[ RMQ(D,R[t],R[s]) ] );

    }
    return 0;
}
