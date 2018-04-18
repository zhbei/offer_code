#include <iostream>
#include <cstdio>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int v){
		val = v;
	}
};
void PrintList(ListNode* head){
	while(head != NULL){
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
void PrintListNode(ListNode * head){
	if(head != NULL)
		cout << head->val << endl;
	else
		cout << "NULL" << endl;
}
void ConnectListNodes(ListNode* &l,ListNode*& s){
	l->next = s;
}

ListNode* reverseList(ListNode * head){
	if(head == NULL || head->next == NULL)
		return head;
	ListNode* newHead = head, *cur = head->next,*nextNode;
	newHead->next = NULL;
	while(cur != NULL){
		nextNode = cur->next;
		cur->next = newHead;
		newHead = cur;
		cur = nextNode;
	}
	return newHead;
}

// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = reverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test(pNode1);

}

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = new ListNode(1);

    Test(pNode1);

}

// 输入空链表
void Test3()
{
    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}