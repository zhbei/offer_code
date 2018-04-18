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

ListNode* merge(ListNode* head1,ListNode* head2){
	if(head1 == NULL)return head2;
	if(head2 == NULL)return head1;
	ListNode* newHead = NULL;
	if(head1->val < head2->val){
		newHead = head1;
		head1 = head1->next;
	}else{
		newHead = head2;
		head2 = head2->next;
	}
	ListNode* pre = newHead;
	while(head1 != NULL || head2 != NULL){
		int val1 = head1==NULL?INT_MAX:head1->val;
		int val2 = head2==NULL?INT_MAX:head2->val;
		if(val1 < val2){
			pre->next = head1;
			pre = head1;
			head1 = head1->next;
		}else{
			pre->next = head2;
			pre = head2;
			head2 = head2->next;
		}
	}
	return newHead;
}

// ====================测试代码====================
ListNode* Test(char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode* pMergedHead = merge(pHead1, pHead2);
    PrintList(pMergedHead);
    
    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode6 = new ListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode6 = new ListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void Test4()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode5 = new ListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pMergedHead = Test("Test4", pNode1, nullptr);

}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test5()
{
    ListNode* pMergedHead = Test("Test5", nullptr, nullptr);
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