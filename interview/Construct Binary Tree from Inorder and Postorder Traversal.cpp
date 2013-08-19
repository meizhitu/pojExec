#include <iostream>
#include <vector>

using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
TreeNode * compute(vector<int> &inorder,int s,int e, vector<int> &postorder,int idx)
{
	if(idx<0) return 0;
	if(s>e) return 0;
	cout <<postorder[idx]<<endl;
	
	TreeNode *parent = new TreeNode(postorder[idx]);
	int i =0;
	for(i = s;i<=e;i++)
		if(inorder[i] == postorder[idx])
			break;
	//计算左枝的大小
	int lsize = (i-1-s)+1;
	//计算右枝的大小
	int rsize = (e-i-1)+1;
	
	parent->left = compute(inorder,s,i-1,postorder,idx-(rsize)-1);
	if(rsize>0)
		parent->right = compute(inorder,i+1,e,postorder,idx-1);
	return parent;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	int postLen = postorder.size();
	if(inorder.size()==0 && postLen==0) return 0;
	return compute(inorder,0,inorder.size()-1,postorder,postLen-1);
}
int main(){
	vector<int> inorder;
	inorder.push_back(2);
	inorder.push_back(3);
	inorder.push_back(1);
	vector<int> postorder;
	postorder.push_back(3);
	postorder.push_back(2);
	postorder.push_back(1);
	buildTree(inorder,postorder);
}