#include <iostream>
#include <stack>

using namespace std;
struct ListNode{
	int val;
	ListNode* next;
	ListNode(int v){
		val = v;
	}
};
void printList(ListNode* head){
	stack<int> stk;
	if(head == NULL)return;
	while(head != NULL){
		stk.push(head->val);
		head = head->next;
	}
	while(!stk.empty()){
		cout << stk.top() << endl;
		stk.pop();
	}
}
void printList2(ListNode* head){
	if(head != NULL){
		printList2(head->next);
		cout << head->val << endl;
	}
}

void test(){

	ListNode *head1 = new ListNode(1);
	ListNode *head2 = new ListNode(11);
	ListNode *head3 = new ListNode(3);
	ListNode *head4 = new ListNode(4);
	ListNode *head = new ListNode(5);
	head2->next = head1;
	head3->next = head2;
	head4->next = head3;
	head->next = head4;
	printList(head);
	printList2(head);
	
}

int main(){
	test();
	return 0;
}