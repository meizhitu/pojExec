#include <iostream>
#include <queue>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
/*
void compute(TreeNode *node,vector<int> & nums){
	if(node == 0 )return;
	compute(node->left,nums);
	nums.push_back(node->val);
	compute(node->right,nums);
}

bool isValidBST(TreeNode *root) {
	if(root == 0 )return true;
	vector<int> nums;
	compute(root,nums);
	for(int i =0;i<nums.size()-1;i++)
		if(nums[i]>=nums[i+1])
			return false;
	return true;
}
*/
bool isValidBST(TreeNode *root) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	return helper(root,INT_MIN,INT_MAX); //INT_MIN and INT_MAX are the minimum and maximum number presented by integer type
}
   
bool helper(TreeNode *root, int min, int max){
	if(root==NULL)
	{
		return true;
	}
	//这个地方写的很巧妙
	if(root->val > min && root->val<max 
		&& helper(root->left,min,root->val)
			&& helper(root->right,root->val,max))
				return true;
	else
		return false;
}
int main(){}