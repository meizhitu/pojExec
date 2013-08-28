//DFS
/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/
#include <iostream>
#include <map>	  
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
//这道题的关键是说，一定是从根到某个叶子节点的总和为sum
bool dfs(TreeNode * node,int sum,int pathSum){
	if(node == 0) return false;
	if(node->left == 0 && node->right == 0) return  sum == pathSum+node->val;
	pathSum += node->val;
	if(dfs(node->left,sum,pathSum))return true;
	if(dfs(node->right,sum,pathSum))return true;
	return false;
}
bool hasPathSum(TreeNode *root, int sum) {
	//根据题目的oj，如果树空，sum==0，返回false；
	if(root == 0) return false; 
    return dfs(root,sum,0);
}
int main(){
	TreeNode root(1);
	TreeNode node1(2);
	TreeNode node2(3);
	TreeNode node3(4);
	TreeNode node4(5);

	root.val = 1;
	node4.val = 5;
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
	node2.right = &node4;
	cout<<hasPathSum(&root,9)<<endl;

}