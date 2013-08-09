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
int compute(TreeNode * node,int * max){
	if(node==NULL) return 0;
	if(node->left == NULL && node->right == NULL){
		if(*max < node->val)
			* max = node->val;
		return node->val;
	}
	int left = compute(node->left,max);
	//cout <<"left "<<left<<" max "<<*max<<endl;
	int right = compute(node->right,max);
	//cout <<"right "<<right<<" max "<<*max<<endl;
	int val = node->val;
	//将左右枝和left-sub->node->right-sub分开计算。
	if(maxIns(left,right)>0)
		val +=maxIns(left,right);
	int leftRight = node->val;
	if(node->left)
		leftRight+= (node->left)->val;
	if(node->right)
		leftRight += (node->right)->val; 
	//cout <<"lf "<<leftRight<<endl;
	// = (node->right)->val+node->val+node->left->val;
	if(*max < leftRight)
		*max = leftRight;
	if(*max < val)
		*max = val;
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