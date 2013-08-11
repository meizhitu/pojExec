//队列
#include <iostream>
#include <queue>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
vector<vector<int> > ret;
vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
	ret.clear();
	if(root ==0) return ret;
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	vector<int> level;
	level.clear();
	int levelN = 1;
	while(!q.empty()){
		TreeNode * node = q.front();
		q.pop();
		if(node){
			level.push_back(node->val);
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}
		else{		
			if(levelN%2==0)
				reverse(level.begin(),level.end());	
			for(int i = 0 ; i< level.size();i++)
				cout << level[i]<<" ";
			cout << endl;
			ret.push_back(level);
			level.clear();
			levelN ++;
			//此处注意，如果树已经全部取出了，则不需要再压入NULL
			if(q.empty()) break;
			q.push(NULL);
		}
	
	}
	//这里是针对Binary Tree Level Order Traversal II所作的修改，真蛋疼
	//reverse(ret.begin(),ret.end());
	return ret;
}
int main(){
 TreeNode root(1);
 TreeNode node1(2);
 TreeNode node2(3);
 TreeNode node3(4);
 TreeNode node4(5);
 /*
 node1.left = node1.right = 0 ;
 node4.left = node4.right = 0 ;

 node3.left = node3.right = 0 ;
 node2.left = node2.right =0;
 */
 root.right = &node1;
 /*
 root.right = &node2;
 node1.right = 0;
 node1.left = &node3;
 node2.right = &node4;
 */
zigzagLevelOrder(&root);
}