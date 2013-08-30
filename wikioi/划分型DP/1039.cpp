/*
将n的整数进行k个划分的方案数，且每个方案数不重复。
	7划分为3个，1 1 5，5 1 1，1 5 1则为重复方案。
解法详情：
http://blog.csdn.net/re_cover/article/details/9383177
将原来的问题进行了转换，跪了。
由于原来是k份划分，因此新的模型中的最大一个元素必然是k。由于原来是k份划分，因此新的模型中的最大一个元素必然是k。
求n的k份划分的方案总数问题转化为根据新模型将n做任意划分，且其中最大的一个部分恰好是k的问题。

求解这个新的模型可以用递推的方法，用f (a,b)表示把b做任意份剖分，
其中最大的一个部分等于a的方案总数，用g(a,b)表示把b做任意份划分，其中最大的一个部分不大于a的方案总数，则有：
f(a, b) = g(a, b - a);
g(a, b) ＝ f(1, b) + f(2, b) +...+ f(a, b);

又因为f(1, b) + f(2, b) +...+ f(a - 1, b) = g(a - 1, b);
所以
g(a, b)  =  f(1, b) +...+ f(a - 1, b) ＋f(a, b) 
         =  g(a - 1, b) + g(a, b - a) (1 <= i <= a - 1)
			 输入参数n,k,所需要求解的是f(k,n)=g(k,n-k) 
*/
#include <stdio.h>
#include <string.h>
int main()
{
	int n, k, g[10][205];
	while(scanf("%d%d", &n, &k) != EOF)
	{
		memset(g, 0, sizeof(g));
		for(int j = 0; j <= n; j++)
			g[1][j] = 1;
		for(int i = 2; i <= k; i++)
			for(int j = 0; j <= n - k; j++)
				if(j >= i)
					g[i][j] = g[i - 1][j] + g[i][j - i];
				else
					g[i][j] = g[i - 1][j];
		printf("%d\n", g[k][n - k]);
	} 
} 