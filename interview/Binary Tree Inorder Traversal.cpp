//中序遍历，有时间用循环做。
vector<int> ret;
void compute(TreeNode * node,vector<int> &list){
	if(node == 0 )return;
	compute(node->left,list);
	list.push_back(node->val);
	compute(node->right,list);
}
vector<int> inorderTraversal(TreeNode *root) {
	if(root== 0)return vector<int>();
	ret.clear();
	compute(root,ret);
	return ret;
}
