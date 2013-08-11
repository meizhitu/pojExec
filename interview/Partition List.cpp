#include <iostream>
using namespace std;
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}ListNode;
ListNode *partition(ListNode *head, int x) {
	if(head==0) return 0;
	ListNode* newH = new ListNode(0);
	ListNode * p = head;
	ListNode * np = newH;
	ListNode * last;
	 
	while(p){
		if(p->val < x)
		{
			np->val = p->val;
			np->next = new ListNode(0);
			last = np;
			np = np->next;
		}
		p = p->next;
	}
	p = head;
	while(p){
		if(p->val >=x){
			np->val = p->val;
			np->next = new ListNode(0);
			last = np;
			np = np->next;
		}
		p = p ->next;
	}
	last->next = 0;
	return newH;
}	
int main(){
	ListNode * head = new ListNode(1);
	ListNode * node = new ListNode(1);
	head->next = node;
	ListNode *newH = partition(head,0);
	while(newH)
	{
		cout << newH->val<<endl;
		newH = newH->next;
	}
}