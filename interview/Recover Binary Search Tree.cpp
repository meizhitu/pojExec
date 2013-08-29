#include <iostream>
#include <queue>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
//O(n)
void compute(TreeNode *node,vector<int> & nums,vector<TreeNode*> &nodes){
	if(node == 0 )return;
	compute(node->left,nums,nodes);
	nums.push_back(node->val);
	nodes.push_back(node);
	compute(node->right,nums,nodes);
}
void recoverTree(TreeNode *root) {
	if(root == 0) return ;
	
	vector<int> nums;
	vector<TreeNode*> nodes;
	compute(root,nums,nodes);
	sort(nums.begin(),nums.end());
	for(int i =  0;i<nums.size();i++)
		nodes[i]->val = nums[i];
}
//O(1)的存储空间。
void recoverTree(TreeNode *root)
{     
	TreeNode *f1=NULL, *f2=NULL;
	TreeNode  *current,*pre, *parent=NULL;

	if(root == NULL)
		return;
	bool found = false;
	current = root;
	while(current != NULL)
	{                
		if(current->left == NULL)
		{
			//为了检查是否存在乱序的点而添加的代码
			if(parent && parent->val > current->val)
			{
				if(!found)
				{
					f1 = parent;
					found = true;
				}
				f2 = current;
			}
			//为了检查是否存在乱序的点而添加的代码
			parent = current;
			current = current->right;     
		}   
		else
		{
			/* Find the inorder predecessor of current */
			pre = current->left;
			while(pre->right != NULL && pre->right != current)
				pre = pre->right;

			/* Make current as right child of its inorder predecessor */
			if(pre->right == NULL)
			{
				pre->right = current; //一开始固定 就是为了寻找中序遍历时的下一个节点。
				current = current->left;
			}

			/* Revert the changes made in if part to restore the original
			tree i.e., fix the right child of predecssor */  
			else
			{
				pre->right = NULL;//恢复树的原本结构。
				if(parent->val > current->val)
				{
					if(!found)
					{
						f1 = parent;       
						found = true;
					}
					f2 = current;
				}
				parent = current;
				current = current->right;     
			} /* End of if condition pre->right == NULL */
		} /* End of if condition current->left == NULL*/
	} /* End of while */

	if(f1 && f2)
		swap(f1->val, f2->val);
}
int main(){
    TreeNode root(0);
    TreeNode node1(1);
 	root.left = &node1;
	recoverTree(&root);
 	cout << root.val<<endl;
}