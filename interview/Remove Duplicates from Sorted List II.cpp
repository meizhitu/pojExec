#include <iostream>
//这道题的前提条件就是list是有序的。
using namespace std;
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}ListNode;
ListNode *deleteDuplicates(ListNode *head) {
	if(head == 0 )return 0;
	ListNode * gard = new ListNode(-1);
	gard->next = head;
	//ListNode * prevH = gard;
	ListNode * prev = gard;
	ListNode * p = head;
	while(p){
		bool isDup = false;
		while(p->next!=0 && p->val == p->next->val){
			ListNode * tmp = p;
			p = p->next;
			isDup = true;
			delete tmp;
		}
		//把这部分删了则可以通过Remove Duplicates from Sorted List
		if(isDup){
			ListNode * tmp = p;
			p = p->next;
			delete tmp;
			continue;//因为p现在指向的节点尚未检测过，因此直接continue直接进入下一次循环的检验。
		}
		//把这部分删了则可以通过Remove Duplicates from Sorted List
		prev->next = p;
		prev = p;
		p = p->next;
	}
	prev->next = p;
	return gard->next;
}
int main(){
ListNode * h=  new ListNode(1);
ListNode * n1 = new ListNode(1);
ListNode * n2 = new ListNode(2);
ListNode * n3 = new ListNode(2);

h->next = n1;
n1->next =n2;
n2->next = n3;

h = deleteDuplicates(h);
while(h){
	cout <<h->val<<endl;
	h= h->next;
}
}