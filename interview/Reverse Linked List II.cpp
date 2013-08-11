
#include <iostream>
using namespace std;
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}ListNode;
ListNode *reverseBetween(ListNode *head, int m, int n) {
	if(head==0) return head;
	if(m>=n) return head;
	ListNode * p = head;
	ListNode * prev = 0;
	int i =1;
	for(i = 1; p&&i<m;i++){
		prev = p;
		p = p->next;
	}
	if(p==0) return head;
	ListNode * cur = p->next;
	ListNode * start = p;
	ListNode * next;
 	
	while(i<n && cur){//2->1->3->4  1->2<-3->4		
		next = cur->next;
		cur->next = start;
		start = cur;
		cur = next;
		i++;
	}
	if(prev)
		prev->next = start;
	else
		head = start;
 	p->next = cur;	
	return head;
}
int main(){
	ListNode *head = new ListNode(1);
	ListNode * n1 = new ListNode(2);
	ListNode * n2 = new ListNode(3);
	ListNode * n3 = new ListNode(4);
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	head = reverseBetween(head,2,3);
	while(head){
		cout <<head->val<<endl;
		head = head->next;
	}
}