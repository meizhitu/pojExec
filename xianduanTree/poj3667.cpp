/*
分析：
线段树，节点内存入左连续块，右连续块，以及当前区间内的最大连续块
将订房服务分为两步：
1.查询是否存在d连续块，若存在，返回r
2.根据1，进行实际的住房操作，即将[r,r+d-1]区间住满
退房服务，与2类似
网上搜的代码，可以AC，用来学习。
*/
#include<stdio.h>
const int N = 50000+10;
/*节点*/
struct node
{
	int left,right;
	int cval;//该区间内最大的连续块长度
	int lval,rval;//左、右边界连续块得长度
};
node tree[N*3];

//将id所对应的区间置满或置空
inline void initNode(int id,int state)
{
	int len = tree[id].right - tree[id].left+1;
	tree[id].cval = state*len;
	tree[id].lval = tree[id].cval;
	tree[id].rval = tree[id].cval;
}
inline int max(int a,int b)
{
	return a>b?a:b;
}
//获得id所在区间的长度
inline int getLen(int id)
{
	return tree[id].right-tree[id].left+1;
}

//建树
void createTree(int left,int right,int id)
{
	tree[id].left=left;
	tree[id].right = right;
	//1表示区间空
	initNode(id,1);
	if(tree[id].left == tree[id].right)return;
    
	int mid = (left+right)>>1;
	createTree(left,mid,2*id);
	createTree(mid+1,right,2*id+1);
}

//查询是否存在长度为need的连续段，若存在返回其左端所在位置
int search(int need,int id)
{
	if(tree[id].cval<need)return 0;
	if(tree[id].left==tree[id].right)return tree[id].left;
	//判断左边的空间是否够
	if(tree[id].lval>=need)return tree[id].left; 
  	//因为tree[id].lval来自于tree[id<<1].lval,如果不够，直接去看id<<1的最大连续区间是否够
	if(tree[2*id].cval>=need)
		return search(need,2*id);
	else
		if(tree[2*id].rval+tree[2*id+1].lval>=need)
			return tree[2*id].right-tree[2*id].rval+1;
	else
		return search(need,2*id+1);
}

/*更新left,right区间，将其置空或置满*/
void update(int left,int right,int id,int state)
{
	int len = tree[id].right - tree[id].left+1;
	if(tree[id].left>=left&&tree[id].right<=right)
	{
		initNode(id,state);
		return;
	}
    
	int mid = (tree[id].left+tree[id].right)>>1;

	if(tree[id].cval == len || tree[id].cval == 0)
	{
		int st = 0;
		if(tree[id].cval!=0)st = 1;
		initNode(2*id,st);
		initNode(2*id+1,st);
	}
     
	if(right<=mid)
		update(left,right,2*id,state);
	else
		if(left>mid)
			update(left,right,2*id+1,state);
	else
	{
		update(left,mid,2*id,state);
		update(mid+1,right,2*id+1,state);
	}
  
	tree[id].lval = tree[2*id].lval;
	//如果左孩子全部为空，则可以对接上右孩子的lval
	if(tree[id].lval==getLen(2*id))
		tree[id].lval+=tree[2*id+1].lval;
	tree[id].rval = tree[2*id+1].rval;
	//如果右孩子全部为空，则可以对接上左孩子的rval
	if(tree[id].rval== getLen(2*id+1))
		tree[id].rval +=tree[2*id].rval;
	tree[id].cval = tree[2*id].rval+tree[2*id+1].lval;
	//因为在左孩子中，最大的连续区间就是cval了（不管是lval或rval）
	tree[id].cval = max(tree[2*id].cval,tree[id].cval);
	tree[id].cval = max(tree[2*id+1].cval,tree[id].cval);
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	createTree(1,n,1);
	int f,d,x;
	while(m--)
	{
		scanf("%d",&f);
		if(f==1)
		{
			scanf("%d",&d);
			int r = search(d,1);
			printf("%d\n",r);
			if(r)
			{
				update(r,r+d-1,1,0);//放满
			}
		}
		else
		{
			scanf("%d%d",&x,&d);
			update(x,x+d-1,1,1);
		}
	}
	return 0;
}