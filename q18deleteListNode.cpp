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
}
void ConnectListNodes(ListNode* &l,ListNode*& s){
	l->next = s;
}
void DeleteNode(ListNode** head,ListNode *cur){
	if(*head == NULL || cur == NULL)
		return ;
	if(*head == cur){
		*head = cur->next;
		cur->next = NULL;
		delete cur;
		return;
	}
	if(cur->next != NULL){
		ListNode* nextNode = cur->next;
		cur->val =  nextNode->val;
		cur->next = nextNode->next;
		nextNode->next = NULL;
		delete nextNode;
	}else{
		ListNode* last = *head;
		while(last->next != NULL && last->next != cur){
			last = last->next;
		}
		if(last->next == cur){
			last->next = cur->next;
			cur->next = NULL;
			delete cur;
		}
	}
}
// ====================测试代码====================
void Test(ListNode* pListHead, ListNode* pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);
    
    printf("The result list is: \n");
    PrintList(pListHead);
}

// 链表中有多个结点，删除中间的结点
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

    Test(pNode1, pNode3);


}

// 链表中有多个结点，删除尾结点
void Test2()
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

    Test(pNode1, pNode5);


}

// 链表中有多个结点，删除头结点
void Test3()
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

    Test(pNode1, pNode1);


}

// 链表中只有一个结点，删除头结点
void Test4()
{
    ListNode* pNode1 = new ListNode(1);

    Test(pNode1, pNode1);
}

// 链表为空
void Test5()
{
    Test(nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}