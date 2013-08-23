//网上找的代码，神奇啊 深搜+树状数组
/*
因为子树在变化，需要把子树映射到底层数组上，利用dfs记录节点i对应的start[i]和end[i]，然后求子树的和就直接sum(end[i])-sum(start[i]-1)
*/
#include <iostream>
#include <cstdio>
using namespace std;

int n, m;
int inc = 0;
int num[100001];
int start[100001];
int end[100001];

//要用到的广义表的结构
struct TREE 
{
	int data;
	TREE * next;
};
TREE tree[100001];

void dfs(int pos)
{
	int i, j, k;
	start[pos] = ++ inc;
	TREE *p = tree[pos].next;
	while (p)
	{
		if (start[p->data] == 0)
		{
			dfs(p->data);
		}
		p = p->next;
	}
	end[pos] = inc;
}

//中间用到的规律值
int lowBit(int x)
{
	return x&(-x);
}
//求从开始到这里的和
int sSum(int end)
{
	int sum = 0;
	while (end > 0)
	{
		sum += num[end];
		end -= lowBit(end);
	}
	return sum;
}
//更新自己并且和自己相关的
void change(int pos, int tmp)
{
	while (pos <= n)
	{
		num[pos] += tmp;
		pos += lowBit(pos);
	}
}
int main()
{
	int j,k,s,t;
	scanf("%d", &n);
	for (int i = 1; i < n; i ++)
	{
		//每一个点都建一个长长的链表，表示自己的一个分支
		scanf("%d%d", &s, &t);
		TREE *p = new TREE;
		p->data = t;
		p->next = tree[s].next;
		tree[s].next = p;

		TREE *q = new TREE;
		q->data = s;
		q->next = tree[t].next;
		tree[t].next = q;

	}
	//映射到树状数组
	dfs(1);
	//每个初始化有一个苹果
	for (int i = 1; i <= n; i ++)
	{
		change(i, 1);
	}
	char ch;
	scanf("%d", &m);
	for (int i = 0; i < m; i ++)
	{
		getchar();
		scanf("%c%d", &ch, &j);
		if (ch == 'C')
		{
			int sum = sSum(start[j]);
			sum -= sSum(start[j] - 1);
			if (sum == 1)
			{
				change(start[j], -1);
			}
			else
			{
				change(start[j], 1);
			}
		}
		else
		{
			int sum = sSum(end[j]);
			sum -= sSum(start[j] - 1);
			printf("%d\n", sum);
		}
	}
	return 0;
}