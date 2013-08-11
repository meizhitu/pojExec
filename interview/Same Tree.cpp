/*判断两棵树是否相同*/
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
		return compute(p->left,q->left)&&compute(p->right,q->right);
	return false;
}
bool isSameTree(TreeNode *p, TreeNode *q) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
	if(q==0 && p==0) return true;
	if(q==0 || p ==0) return false;
	return compute(p,q);
}
int main(){}