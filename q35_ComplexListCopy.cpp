#include <iostream>
#include <cstdio>

using namespace std;

struct ComplexListNode
{
	int val;
	ComplexListNode *m_pNext;
	ComplexListNode *m_pSibling;
};
ComplexListNode* CreateNode(int nValue)
{
    ComplexListNode* pNode = new ComplexListNode();
    
    pNode->val = nValue;
    pNode->m_pNext = nullptr;
    pNode->m_pSibling = nullptr;

    return pNode;
}

void BuildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != nullptr)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}

void PrintList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        printf("The value of this node is: %d.\n", pNode->val);

        if(pNode->m_pSibling != nullptr)
            printf("The value of its sibling is: %d.\n", pNode->m_pSibling->val);
        else
            printf("This node does not have a sibling.\n");

        printf("\n");

        pNode = pNode->m_pNext;
    }
}

ComplexListNode* copyComplexList(ComplexListNode* source){
	ComplexListNode* dest = NULL;
	if(source == NULL)return dest;
	ComplexListNode* first = source;
	while(first != NULL){
		ComplexListNode *tmp = new ComplexListNode();
		tmp->val = first->val;
		tmp->m_pNext = first->m_pNext;

		first->m_pNext = tmp;

		first = tmp->m_pNext;
	}
	ComplexListNode *second = NULL,*pre = NULL;
	first = source;
	while(first != NULL){
		second = first->m_pNext;
		second->m_pSibling = first->m_pSibling == NULL ? NULL:first->m_pSibling->m_pNext;
		first = second->m_pNext;
	}
	first = source;
	dest = first->m_pNext;
	while(first != NULL){
		second = first->m_pNext;
		first->m_pNext = second->m_pNext;
		if(pre == NULL)
			pre = second;
		else{
			pre->m_pNext = second;
			pre = second;
			pre->m_pNext = NULL;
		}
		first = first->m_pNext;
	}
	return dest;
}


// ====================测试代码====================
void Test(const char* testName, ComplexListNode* pHead)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The original list is:\n");
    PrintList(pHead);

    ComplexListNode* pClonedHead = copyComplexList(pHead);

    printf("The cloned list is:\n");
    PrintList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, pNode3);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

// m_pSibling指向结点自身
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//         |       | /|\           /|\
//         |       | --             |
//         |------------------------|
void Test2()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode5);
    BuildNodes(pNode3, pNode4, pNode3);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test2", pNode1);
}

// m_pSibling形成环
//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//          |              /|\
//          |               |
//          |---------------|
void Test3()
{
    ComplexListNode* pNode1 = CreateNode(1);
    ComplexListNode* pNode2 = CreateNode(2);
    ComplexListNode* pNode3 = CreateNode(3);
    ComplexListNode* pNode4 = CreateNode(4);
    ComplexListNode* pNode5 = CreateNode(5);

    BuildNodes(pNode1, pNode2, nullptr);
    BuildNodes(pNode2, pNode3, pNode4);
    BuildNodes(pNode3, pNode4, nullptr);
    BuildNodes(pNode4, pNode5, pNode2);

    Test("Test3", pNode1);
}

// 只有一个结点
void Test4()
{
    ComplexListNode* pNode1 = CreateNode(1);
    BuildNodes(pNode1, nullptr, pNode1);

    Test("Test4", pNode1);
}

// 鲁棒性测试
void Test5()
{
    Test("Test5", nullptr);
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

