#include <iostream>
using namespace std;
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}ListNode;
//算法复杂度为O(n)的写法
ListNode *deleteDuplicates(ListNode *head) {
	if(head == 0) return 0;
	ListNode * prev = head;
	ListNode * p = head->next;
	while(p){
		if(prev->val == p->val){
			ListNode * tmp = p;
			p = p->next;
			prev->next = p;
			delete tmp;
		}
		prev = p;
		p = p->next;
	}
	return head;
}
//这个写法比较屎复杂度到了o（n^2）
ListNode *deleteDuplicates(ListNode *head) {
       // Start typing your C/C++ solution below
       // DO NOT write int main() function
	if(head == 0 )return 0;
	ListNode * prev = head;
	ListNode * p = head->next;
	while(p){
		ListNode * hp = head;
		bool isDel = false;
		while(hp && hp!=p){
			if(hp->val == p->val){
				prev->next = p->next;
				p = prev->next;
				isDel = true;
			}
			hp = hp->next;
		}
		if(!isDel){
			prev = p;
			p = p->next;
		}
	}
	return head;
}