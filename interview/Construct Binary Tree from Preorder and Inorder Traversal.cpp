#include <iostream>
#include <vector>

using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

TreeNode * compute(vector<int> &preorder,int idx, vector<int> &inorder,int s,int e){
	if(idx>=preorder.size()) return 0;
	if(s>e) return 0;
	cout <<preorder[idx]<<endl;
	TreeNode * n = new TreeNode(preorder[idx]);
	int i ;
	for(i = s;i<=e;i++)
		if(inorder[i] == preorder[idx])
			break;
	//左右枝大小。
	int lsize = i-1-s+1;
	int rsize = e-(i+1)+1;
	if(lsize>0)
		n->left = compute(preorder,idx+1,inorder,s,i-1);
	n->right = compute(preorder,idx+1+lsize,inorder,i+1,e);
	return n;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
	if(preorder.size()==0 && inorder.size()==0)return 0;
	return compute(preorder,0,inorder,0,inorder.size()-1);
}
int main(){
	vector<int> preorder;
	preorder.push_back(2);
	preorder.push_back(3);
	preorder.push_back(1);
	vector<int> inorder;
	inorder.push_back(3);
	inorder.push_back(2);
	inorder.push_back(1);
	buildTree(preorder,inorder);
}
