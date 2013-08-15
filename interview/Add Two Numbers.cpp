
#include <iostream>
using namespace std;
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}ListNode;
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	ListNode * p1 = l1;
	ListNode * p2 = l2;
	ListNode * gard = new ListNode(0);
	ListNode * p = gard;
	
	int carry = 0; 
	while(p1&&p2){
		int sum = p1->val+p2->val+carry;
		carry = sum/10;
		if(!p->next)
			p->next = new ListNode(sum%10);
		p1 = p1->next;
		p2 = p2->next;
		p = p->next;
	}
	while(p1){
		int sum = p1->val+carry;
		p->next = new ListNode(sum%10);
		carry = sum/10;
		p = p ->next;
		p1 = p1->next;
	}
	while(p2){
		int sum = p2->val+carry;
		p->next = new ListNode(sum%10);
		carry = sum/10;
		p2 = p2->next;
		p = p->next;
	}
	if(carry>0)
		p->next = new ListNode(carry);
	return gard->next;
}