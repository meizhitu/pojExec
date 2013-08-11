/*
扁平化一棵树，就是前序遍历
*/
#include <iostream>
	using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

TreeNode* compute(TreeNode * node){
	if(node == 0 ) return 0;
	if(node->left==0 && node->right==0) return node;
	TreeNode * rightC = node->right;
	node->right = compute(node->left);
	node->left = 0;
	TreeNode * p = node;
	//此处之前做错，需要把指针移动到右侧最尾处，接上原右枝的扁平化链表。
	while(p && p->right){
		p = p->right;
	}
	p->right = compute(rightC);
	p->left = 0 ;
	return node;
}
 void flatten(TreeNode *root) {
	 if(root == 0) return ;
	 //visit self
	 //visit self->left
	 compute(root);
 }
 //中序检查结果。
 void innerOrder(TreeNode * node){
	 if(node == 0) return;
	 innerOrder(node->left);
	 cout <<node->val<<endl;
	 innerOrder(node->right);
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
	 flatten(&root);
	 innerOrder(&root);
 }