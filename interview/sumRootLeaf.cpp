#include <iostream>
//a了
/*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

		Return the sum = 12 + 13 = 25.

*/
using namespace std;
typedef struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
}TreeNode;
int compute(TreeNode * node,int val){
	if(node == NULL)
		return 0;
	if(node->left == NULL && node->right == NULL) {
		return 10*val+node->val;
	}
	return compute(node->left,10*val+node->val)+compute(node->right,10*val+node->val);
 }

int main(){
	TreeNode root ;
	root.val = 1;
	TreeNode l1 ;
	l1.val =4;
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
	root.right =&l3;
	
	cout<<compute(&root,0) <<endl;
}