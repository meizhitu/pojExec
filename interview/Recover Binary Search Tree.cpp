#include <iostream>
#include <queue>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
//O(n)
void compute(TreeNode *node,vector<int> & nums,vector<TreeNode*> &nodes){
	if(node == 0 )return;
	compute(node->left,nums,nodes);
	nums.push_back(node->val);
	nodes.push_back(node);
	compute(node->right,nums,nodes);
}
void recoverTree(TreeNode *root) {
	if(root == 0) return ;
	
	vector<int> nums;
	vector<TreeNode*> nodes;
	compute(root,nums,nodes);
	sort(nums.begin(),nums.end());
	for(int i =  0;i<nums.size();i++)
		nodes[i]->val = nums[i];
}
int main(){
    TreeNode root(0);
    TreeNode node1(1);
 	root.left = &node1;
	recoverTree(&root);
 	cout << root.val<<endl;
}