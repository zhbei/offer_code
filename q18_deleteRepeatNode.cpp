#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <memory.h> 
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
void DeleteDuplication(ListNode** head){
	if(*head == NULL || (*head)->next == NULL)
		return;
	ListNode* first = *head, *last = NULL;
	while(first != NULL){
		ListNode* nextNode = first->next;
		if(nextNode != NULL && nextNode->val == first->val){
			ListNode *toBeDelete = first;
			int val = first->val;
			while(toBeDelete != NULL && toBeDelete->val == val){
				nextNode = toBeDelete->next;
                //this code is very important
                // if you do not set the next to NULL
                //the ListNode point by next will be delete !!!!
				toBeDelete->next = NULL;
				delete toBeDelete;
				toBeDelete = nextNode;
			}
			if(last != NULL){
				last->next = nextNode;
			}else{
				*head = nextNode;
			}
			first = nextNode;
		}else{
			last = first;
			first = nextNode;
		}
	}


}
// ====================测试代码====================
void Test(char* testName, ListNode** pHead, int* expectedValues, int expectedLength)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);


    DeleteDuplication(pHead);

    int index = 0;
    ListNode* pNode = *pHead;
    while(pNode != nullptr && index < expectedLength)
    {
        if(pNode->val != expectedValues[index])
            break;

        pNode = pNode->next;
        index++;
    }

    if(pNode == nullptr && index == expectedLength)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 某些结点是重复的
void Test1()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode5 = new ListNode(4);
    ListNode* pNode6 = new ListNode(4);
    ListNode* pNode7 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 5 };
    Test("Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

}

// 没有重复的结点
void Test2()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);
    ListNode* pNode6 = new ListNode(6);
    ListNode* pNode7 = new ListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2, 3, 4, 5, 6, 7 };
    Test("Test2", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));


}

// 除了一个结点之外其他所有结点的值都相同
void Test3()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(1);
    ListNode* pNode4 = new ListNode(1);
    ListNode* pNode5 = new ListNode(1);
    ListNode* pNode6 = new ListNode(1);
    ListNode* pNode7 = new ListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2 };
    Test("Test3", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));


}

// 所有结点的值都相同
void Test4()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(1);
    ListNode* pNode4 = new ListNode(1);
    ListNode* pNode5 = new ListNode(1);
    ListNode* pNode6 = new ListNode(1);
    ListNode* pNode7 = new ListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode* pHead = pNode1;

    Test("Test4", &pHead, nullptr, 0);

}

// 所有结点都成对出现
void Test5()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(2);
    ListNode* pNode4 = new ListNode(2);
    ListNode* pNode5 = new ListNode(3);
    ListNode* pNode6 = new ListNode(3);
    ListNode* pNode7 = new ListNode(4);
    ListNode* pNode8 = new ListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    Test("Test5", &pHead, nullptr, 0);

}

// 除了两个结点之外其他结点都成对出现
void Test6()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);
    ListNode* pNode3 = new ListNode(2);
    ListNode* pNode4 = new ListNode(3);
    ListNode* pNode5 = new ListNode(3);
    ListNode* pNode6 = new ListNode(4);
    ListNode* pNode7 = new ListNode(5);
    ListNode* pNode8 = new ListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 2, 4 };
    Test("Test6", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

}

// 链表中只有两个不重复的结点
void Test7()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1, 2 };
    Test("Test7", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

}

// 结点中只有一个结点
void Test8()
{
    ListNode* pNode1 = new ListNode(1);

	pNode1->next = NULL;   

    ListNode* pHead = pNode1;

    int expectedValues[] = { 1 };
    Test("Test8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));


}

// 结点中只有两个重复的结点
void Test9()
{
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(1);

    ConnectListNodes(pNode1, pNode2);

    ListNode* pHead = pNode1;

    Test("Test9", &pHead, nullptr, 0);
}

// 空链表
void Test10()
{
    ListNode* pHead = nullptr;

    Test("Test10", &pHead, nullptr, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();

    return 0;
}