//树节点的按层遍历
#include <iostream>
#include <queue>
#include <map>

using namespace std;
typedef struct TreeLinkNode {
     TreeLinkNode *left;
     TreeLinkNode *right;
	 int val;
     TreeLinkNode *next;
}TreeLinkNode;

void connect(TreeLinkNode *root) {
	if(root==NULL)return;
	vector<TreeLinkNode*> que;
  	que.push_back(root);
	//最大的问题在于如何确定每一层的结束位置，这里设置了NULL作为标志位。
	que.push_back(NULL);
	int head = 0;
 
	while(head < que.size()){
		TreeLinkNode * node = que[head];
		head ++;
		if(node){
			if(node->left) que.push_back(node->left);
			if(node->right) que.push_back(node->right);
			node->next = que[head];
		}
		else{
			if(head>=que.size())break;
			//标志前一层的结束，同时也标志着下一层的节点全部录入到que里。
			que.push_back(NULL);
		}
	}	
}
int main(){
	TreeLinkNode root ;
	TreeLinkNode node1;
	TreeLinkNode node2;
	TreeLinkNode node3;
	TreeLinkNode node4;

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

	connect(&root);
}