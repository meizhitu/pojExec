/*
Given a binary tree, find the maximum path sum.

	The path may start and end at any node in the tree.

		For example:
Given the below binary tree,

     1
	/ \
   2   3
			Return 6.
*/
		   
#include <iostream>
#include <vector>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
}TreeNode;
int maxIns(int a,int b)
{
	return a>b?a:b;
}
//注意负数情况
int compute(TreeNode * node,int * maxV){
	if(node==NULL) return 0;
	if(node->left == NULL && node->right == NULL){
		if(*maxV < node->val)
			* maxV = node->val;
		return node->val;
	}
	int left = compute(node->left,maxV);
	int right = compute(node->right,maxV);
	int val = node->val;
	//将左右枝和left-sub->node->right-sub分开计算。
	if(max(left,right)>0)
		val +=max(left,right); //从节点到左枝或右枝的最大长度，不包括跨越根节点的情况。
	int leftRight = node->val;
	if(node->left)
		leftRight+= (node->left)->val;
	if(node->right)
		leftRight += (node->right)->val; 
	//最大值不一定需要跨越根节点，可以从任意节点到任意另一节点，所有需要把max放在整个计算中更新。
	*maxV = max(max(leftRight,val),*maxV);
	node->val = val;
	return val;
}
int maxPathSum(TreeNode *root) {
	if(root == 0)return 0;
	int max  = root->val;
	compute(root,&max);
	return max;
}
int main(){
	TreeNode root ;
	root.val = -2;
	TreeNode l1 ;
	l1.val =1;
	root.left = &l1;
	root.right = 0;
	l1.left = l1.right = 0 ;
	/*
	TreeNode l2;
	l2.val = 5;
	TreeNode l3;
	l3.val = 6;
	root.left = &l1;
	l1.left = &l2;
	l1.right = 0;
	l2.left = 0;
	l2.right = 0;
	l3.left = NULL;
	l3.right =0;
	root.right =&l3;*/
		cout << maxPathSum(&root)<<endl;
}