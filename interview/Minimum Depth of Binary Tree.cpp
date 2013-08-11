/*
Given a binary tree, find its minimum depth.

	The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
		*/
#include <iostream>
		using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
int compute(TreeNode *root){
	if(root == 0) return 10000000;
	if(root->left == 0 && root->right ==0) return 1;
	return min(compute(root->left),compute(root->right))+1;
}
int minDepth(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(root == 0) return 0;
	return compute(root);
}
int main(){
	TreeNode root(1);
	TreeNode node1(2);
	TreeNode node2(3);
	TreeNode node3(4);
	TreeNode node4(5);

	 
	node1.left = node1.right = 0 ;
	node4.left = node4.right = 0 ;

	node3.left = node3.right = 0 ;
	node3.val = 4;
	node2.left = node2.right =0;
	node1.val = 2;
	node2.val = 3;
	root.left = &node1;
	root.right = &node2;
	node1.right = 0;
	node1.left = &node3;
	node2.right =0;
	node3.right = &node4;
	cout << minDepth(&root)<<endl;

}