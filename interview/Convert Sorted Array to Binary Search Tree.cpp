#include <iostream>
#include <vector>

using namespace std;
//把一个有序数组变成一颗平衡二叉树。每次取中间的节点作为当前子树的根节点。
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
TreeNode* build(int s,int e,vector<int> &num){
 	if(s>e)return 0;
	int mid = (s+e)>>1;
	TreeNode *lC = build(s,mid-1,num);
	TreeNode *node = new TreeNode(num[mid]);
	node->left = lC;
	node->right = build(mid+1,e,num);
	return node;
}
TreeNode *sortedArrayToBST(vector<int> &num) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
	if(num.size()==0) return NULL;
	return build(0,num.size()-1,num);
}

int main(){
	
	vector<int> num;
	sortedArrayToBST(num);
}