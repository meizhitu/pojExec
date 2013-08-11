#include <iostream>
using namespace std;
typedef struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
}ListNode;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
TreeNode* build(int s,int e,ListNode * &list){
 	if(s>e)return 0;
	int mid = (s+e)>>1;
	TreeNode *lC = build(s,mid-1,list);
	TreeNode *node = new TreeNode(list->val);
	node->left = lC;
	//之前直接用指针去循环找mid位置的数，judge大数的时候时间较长。
	list = list->next;
	node->right = build(mid+1,e,list);
	return node;
}
TreeNode *sortedListToBST(ListNode *head) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
	if(head==0) return NULL;
	ListNode * p = head;
	int len = 0 ;
	while(p){
		len++;
		p = p->next;
	}
	return build(0,len-1,head);
}

int main(){
	ListNode *head = 0;
	
	sortedListToBST(head);
}