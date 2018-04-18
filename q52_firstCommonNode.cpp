#include <iostream>
#include <cstdio>
#include <set>
#include <stack>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
};

ListNode* findFirstCommonNode_1(ListNode* head1,ListNode* head2){
	if(head1 == NULL || head2 == NULL)
		return NULL;
	set<ListNode*> have;
	ListNode *p1 = head1,*p2 = head2;
	while(p1 != NULL){
		have.insert(p1);
		p1 = p1->next;
	}
	set<ListNode*>::iterator common;
	while(p2 != NULL){
		common = have.find(p2);
		if(common != have.end())
			return *common;
		p2 = p2->next;
	}
	return NULL;
}

ListNode* findFirstCommonNode_2(ListNode* head1,ListNode* head2){
	if(head1 == NULL || head2 == NULL)
		return NULL;
	stack<ListNode*> s1,s2;
	ListNode *p1 = head1,*p2 = head2;
	while(p1 != NULL){
		s1.push(p1);
		p1 = p1->next;
	}
	while(p2 != NULL){
		s2.push(p2);
		p2 = p2->next;
	}
	ListNode *last = NULL;
	while(!s1.empty() && !s2.empty()){
		if(s1.top() != s2.top()){
			return last;
		}
		last = s1.top();
		s1.pop();
		s2.pop();
	}
	return (s1.empty() && s2.empty()) ? last : NULL;
}

ListNode* findFirstCommonNode_3(ListNode* head1,ListNode* head2){
	if(head1 == NULL || head2 == NULL)
		return NULL;
	ListNode *p1 = head1,*p2 = head2;
	int len1 = 0, len2 = 0;
	while(p1 != NULL){
		p1 = p1->next;
		++len1;
	}
	while(p2 != NULL){
		++len2;
		p2 = p2->next;
	}
	int dist = 0;
	p1 = head1,p2 = head2;
	if(len1 > len2){
		dist = len1 - len2;
		while(dist > 0){
			--dist;
			p1 = p1->next;
		}

	}else{
		dist = len2 - len1;
		while(dist > 0){
			--dist;
			p2 = p2->next;
		}
	}
	while(p1 != NULL && p2 != NULL){
		if(p1 == p2){
			return p1;
		}
		p1 = p1->next;
		p2 = p2->next;
	}
	return NULL;
}

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->val = value;
    pNode->next = nullptr;

    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        printf("Error to connect two nodes.\n");
    }

    pCurrent->next = pNext;
}

void PrintListNode(ListNode* pNode)
{ 
    if(pNode == nullptr)
    {
        printf("The node is nullptr\n");
    }
    else
    {
        printf("The key in node is %d.\n", pNode->val);
    }
}

void PrintList(ListNode* pHead)
{
    printf("PrintList starts.\n");
    
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->val);
        pNode = pNode->next;
    }

    printf("\nPrintList ends.\n");
}

void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->next;
        delete pNode;
        pNode = pHead;
    }
}

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->val = value;
    pNew->next = nullptr;

    if(*pHead == nullptr)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->next != nullptr)
            pNode = pNode->next;

        pNode->next = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == nullptr || *pHead == nullptr)
        return;

    ListNode* pToBeDeleted = nullptr;
    if((*pHead)->val == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->next;
    }
    else
    {
        ListNode* pNode = *pHead;
        while(pNode->next != nullptr && pNode->next->val != value)
            pNode = pNode->next;

        if(pNode->next != nullptr && pNode->next->val == value)
        {
            pToBeDeleted = pNode->next;
            pNode->next = pNode->next->next;
        }
    }

    if(pToBeDeleted != nullptr)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}

void Test(char* testName, ListNode* pHead1, ListNode* pHead2, ListNode* pExpected)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    ListNode* pResult = findFirstCommonNode_1(pHead1, pHead2);
    ListNode* pResult_1 = findFirstCommonNode_2(pHead1, pHead2);
    ListNode* pResult_2 = findFirstCommonNode_3(pHead1, pHead2);
    if(pResult == pExpected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
    if(pResult_1 == pExpected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
    if(pResult_2 == pExpected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 第一个公共结点在链表中间
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode6);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test1", pNode1, pNode4, pNode6);


}

// 没有公共结点
// 1 - 2 - 3 - 4
//            
// 5 - 6 - 7
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test2", pNode1, pNode5, nullptr);

}

// 公共结点是最后一个结点
// 1 - 2 - 3 - 4 \
//                7
//         5 - 6 /
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);
    ListNode* pNode6 = CreateListNode(6);
    ListNode* pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode7);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    Test("Test3", pNode1, pNode5, pNode7);


}

// 公共结点是第一个结点
// 1 - 2 - 3 - 4 - 5
// 两个链表完全重合   
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test4", pNode1, pNode1, pNode1);

}

// 输入的两个链表有一个空链表
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    Test("Test5", nullptr, pNode1, nullptr);

    DestroyList(pNode1);
}

// 输入的两个链表有一个空链表
void Test6()
{
    Test("Test6", nullptr, nullptr, nullptr);
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
