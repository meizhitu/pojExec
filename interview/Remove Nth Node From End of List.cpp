#include <iostream>
using namespace std;
typedef struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
}ListNode;
ListNode *removeNthFromEnd(ListNode *head, int n) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
	if(head == 0)return 0;
	ListNode * gard = new ListNode(0);
	gard->next = head;
	ListNode * first = head;
	ListNode * prev = gard;
	ListNode * second = head;
	for(int i = 1;i<=n &&first;i++){
		first = first->next;
	}
	while(first){
		first = first->next;
		prev = second;
		second = second->next;
	}
	prev->next = second->next;
	return gard->next;
  }
  int main(){}