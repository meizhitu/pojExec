//DFS
/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

*/
#include <iostream>
#include <vector>	  
				  
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
vector<vector<int> > ret;
void dfs(TreeNode * node,int sum,int pathSum,vector<int> path){
	if(node == 0) return;
	
	if(node->left == 0 && node->right == 0 && sum == pathSum+node->val)
	{
		path.push_back(node->val);
		ret.push_back(path);
		return;
	}	
	pathSum += node->val;
	//深搜是个试探的过程。
	path.push_back(node->val);
	dfs(node->left,sum,pathSum,path);
	dfs(node->right,sum,pathSum,path);
	//试探结束后，要回退。
	path.pop_back();
}
vector<vector<int> > pathSum(TreeNode *root, int sum) {
	ret.clear();
	if(root == 0) return ret; 
 	dfs(root,sum,0,vector<int>());
	return ret;
}

int main(){
	TreeNode root(1);
	TreeNode node1(1);
	TreeNode node2(3);
	TreeNode node3(7);
	TreeNode node4(5);

	 
	node1.left = node1.right = 0 ;
	node4.left = node4.right = 0 ;

	node3.left = node3.right = 0 ;
 	node2.left = node2.right =0;
  	root.left = &node1;
	root.right = &node2;
	node1.right = 0;
	node1.left = &node3;
	node2.right = &node4;
//	cout<<hasPathSum(&root,9)<<endl;
	pathSum(&root,9);
}