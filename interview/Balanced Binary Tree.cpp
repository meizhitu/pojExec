//判断平衡树
#include <iostream>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
bool compute(TreeNode * node,int *height){
	if(node == 0 ){
		*height = 0;
		return true;}
	if(node->left == 0 && node->right ==0){
		*height =1;
		return true;
	}
	//从root往下走，左右高度均为0，通过访问子节点进行修改。
	int leftH = 0;
	int rightH = 0;
	bool leftB = compute(node->left,&leftH);
	bool rightB =compute(node->right,&rightH);
 	*height = max(leftH,rightH)+1;
	if(leftB && rightB){
		return abs(leftH-rightH)<=1;
	}
	//不要忘了
	return false;
}
bool isBalanced(TreeNode *root) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
	if(root==0) return true;
	int height =  0;
	return compute(root,&height);
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
 	node2.left = node2.right =0;
 	root.left = &node1;
	//root.right = &node2;
	node1.right = 0;
	node1.left = &node3;
	//node2.right = &node4;
	cout<<isBalanced(&root)<<endl;
}