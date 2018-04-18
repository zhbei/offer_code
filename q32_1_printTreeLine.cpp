#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct BinaryTreeNode{
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

void printTreeLine(BinaryTreeNode* root){
	if(root == NULL)
		return;
	vector<queue<BinaryTreeNode*>> que(2,queue<BinaryTreeNode*>());
	que[0].push(root);
	BinaryTreeNode *tmp = NULL;
    bool flag = false;
	while(!que[flag].empty()){
		tmp = que[flag].front();
        que[flag].pop();
		cout << tmp->val << " ";
		if(tmp->left != NULL){
			que[!flag].push(tmp->left);
		}
		if(tmp->right != NULL){
			que[!flag].push(tmp->right);
		}
        if(que[flag].empty()){
            flag = !flag;
            cout << endl;
        }
	}
}

// ====================测试代码====================
// ====================辅助测试代码====================
BinaryTreeNode* CreateBinaryTreeNode(double dbValue)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->val = dbValue;
    pNode->left = nullptr;
    pNode->right = nullptr;

    return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->left = pLeft;
        pParent->right = pRight;
    }
}

void DestroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->left;
        BinaryTreeNode* pRight = pRoot->right;

        delete pRoot;
        pRoot = nullptr;

        DestroyTree(pLeft);
        DestroyTree(pRight);
    }
}
void PrintTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->val);

        if(pNode->left != nullptr)
            printf("value of its left child is: %d.\n", pNode->left->val);
        else
            printf("left child is nullptr.\n");

        if(pNode->right != nullptr)
            printf("value of its right child is: %d.\n", pNode->right->val);
        else
            printf("right child is nullptr.\n");
    }
    else
    {
        printf("this node is nullptr.\n");
    }

    printf("\n");
}
void PrintTree(const BinaryTreeNode* pRoot)
{
    PrintTreeNode(pRoot);

    if(pRoot != nullptr)
    {
        if(pRoot->left != nullptr)
            PrintTree(pRoot->left);

        if(pRoot->right != nullptr)
            PrintTree(pRoot->right);
    }
}
void Test(const char* testName, BinaryTreeNode* pRoot)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    //PrintTree(pRoot);

    printf("The nodes from top to bottom, from left to right are: \n");
    printTreeLine(pRoot);

    printf("\n\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode14 = CreateBinaryTreeNode(14);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode16 = CreateBinaryTreeNode(16);

    ConnectTreeNodes(pNode10, pNode6, pNode14);
    ConnectTreeNodes(pNode6, pNode4, pNode8);
    ConnectTreeNodes(pNode14, pNode12, pNode16);

    Test("Test1", pNode10);

    DestroyTree(pNode10);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    Test("Test2", pNode5);

    DestroyTree(pNode5);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test3()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test("Test3", pNode1);

    DestroyTree(pNode1);
}

// 树中只有1个结点
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    Test("Test4", pNode1);

    DestroyTree(pNode1);
}

// 树中没有结点
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

