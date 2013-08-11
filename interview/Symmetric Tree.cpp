#include <iostream>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
bool compute(TreeNode *p,TreeNode *q){
	if(q==0 && p==0) return true;
	if(q==0 || p ==0) return false;
	if(p->val == q->val)
		//左枝等于右枝，右枝等于左枝
		return compute(p->left,q->right)&&compute(p->right,q->left);
	return false;
}
bool isSymmetric(TreeNode *root) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
	if(root==0) return true;
	return compute(root->left,root->right);
   }
   int main(){}