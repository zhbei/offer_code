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

ListNode* kthToTail(ListNode* head,int k){
	int i = 0;
	if(head == NULL)return NULL;
	ListNode* fast = head, *slow = head;
	while(fast != NULL && i < k){
		++i;
		fast = fast->next;
	}
	if(i == k && fast == NULL) return head;
	if(fast == NULL)return NULL;
	while(fast != NULL){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

// 测试要找的结点在链表中间
void Test1()
{
    printf("=====Test1 starts:=====\n");
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 4.\n");
    ListNode* pNode = kthToTail(pNode1, 2);
    PrintListNode(pNode);

}

// 测试要找的结点是链表的尾结点
void Test2()
{
    printf("=====Test2 starts:=====\n");
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 5.\n");
    ListNode* pNode = kthToTail(pNode1, 1);
    PrintListNode(pNode);

}

// 测试要找的结点是链表的头结点
void Test3()
{
    printf("=====Test3 starts:=====\n");
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: 1.\n");
    ListNode* pNode = kthToTail(pNode1, 5);
    PrintListNode(pNode);

}

// 测试空链表
void Test4()
{
    printf("=====Test4 starts:=====\n");
    printf("expected result: nullptr.\n");
    ListNode* pNode = kthToTail(nullptr, 100);
    PrintListNode(pNode);
}

// 测试输入的第二个参数大于链表的结点总数
void Test5()
{
    printf("=====Test5 starts:=====\n");
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = kthToTail(pNode1, 6);
    PrintListNode(pNode);

}

// 测试输入的第二个参数为0
void Test6()
{
    printf("=====Test6 starts:=====\n");
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    printf("expected result: nullptr.\n");
    ListNode* pNode = kthToTail(pNode1, 0);
    PrintListNode(pNode);

}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}