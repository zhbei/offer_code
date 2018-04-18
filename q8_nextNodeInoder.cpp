#include <iostream>
#include <cstdio>
using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	TreeNode(int v){
		val = v;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

TreeNode* nextNode(TreeNode * cur){
	if(cur == NULL)return NULL;
	if(cur->right != NULL){
		TreeNode* right = cur->right;
		while(right->left){
			right = right->left;
		}
		return right;
	}	
	TreeNode* parent = cur->parent;
	
	while(parent != NULL){
		if(parent->left == cur){
			return parent;
		}else{
			cur = parent;
			parent = cur->parent;
		}
	}
	return NULL;
}
void ConnectTreeNodes(TreeNode* pParent, TreeNode* pLeft, TreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;

        if(pLeft != nullptr)
            pLeft->parent = pParent;
        if(pRight != nullptr)
            pRight->parent = pParent;
    }
}
// ====================测试代码====================
void Test(const char* testName, TreeNode* pNode, TreeNode* expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    TreeNode* pNext = nextNode(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
    TreeNode* pNode8 = new TreeNode(8);
    TreeNode* pNode6 = new TreeNode(6);
    TreeNode* pNode10 = new TreeNode(10);
    TreeNode* pNode5 = new TreeNode(5);
    TreeNode* pNode7 = new TreeNode(7);
    TreeNode* pNode9 = new TreeNode(9);
    TreeNode* pNode11 = new TreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8, pNode9);
    Test("Test2", pNode6, pNode7);
    Test("Test3", pNode10, pNode11);
    Test("Test4", pNode5, pNode6);
    Test("Test5", pNode7, pNode8);
    Test("Test6", pNode9, pNode10);
    Test("Test7", pNode11, nullptr);

}

//            5
//          4
//        3
//      2
void Test8_11()
{
    TreeNode* pNode5 = new TreeNode(5);
    TreeNode* pNode4 = new TreeNode(4);
    TreeNode* pNode3 = new TreeNode(3);
    TreeNode* pNode2 = new TreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

    Test("Test8", pNode5, nullptr);
    Test("Test9", pNode4, pNode5);
    Test("Test10", pNode3, pNode4);
    Test("Test11", pNode2, pNode3);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
    TreeNode* pNode2 = new TreeNode(2);
    TreeNode* pNode3 = new TreeNode(3);
    TreeNode* pNode4 = new TreeNode(4);
    TreeNode* pNode5 = new TreeNode(5);

    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test12", pNode5, nullptr);
    Test("Test13", pNode4, pNode5);
    Test("Test14", pNode3, pNode4);
    Test("Test15", pNode2, pNode3);

}

void Test16()
{
    TreeNode* pNode5 = new TreeNode(5);

    Test("Test16", pNode5, nullptr);

}

int main(int argc, char* argv[])
{
    Test1_7();
    Test8_11();
    Test12_15();
    Test16();
}