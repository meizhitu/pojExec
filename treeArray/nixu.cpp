/*
树状数组求逆序对个数，当第i个数加入的时候，查找比i小的数字的个数，那么剩下的i-sum(i)则为比i大的数字个数。
*/
#include <stdio.h>
unsigned long c[10000000];
unsigned long n,ans;
void modify(int k)
{
     for(; k<10000110 ;k+=(-k)&k) c[k]+=1;
}
int get(int k)
{
     int s;
     for(s=0; k>0 ;k-=(-k)&k) s+=c[k];
     return s;
}
int main()
{
	scanf("%d",&n);
    int i,k;
    ans=0;
    for(i=1; i<=n ;i++)
    {
             scanf("%d",&k);
             modify(k);
			 printf("k=%d ret=%d\n",k,i-get(k));
             ans+=i-get(k);
    }
    printf("%d\n",ans);
    return 0;
}