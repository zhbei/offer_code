#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

struct BinaryTreeNode{
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};
bool isPostOrder(vector<int> &seq,int start,int end){
	if(start + 1 >= end)return true;
	int i = start;
    //cout << start << " , " << end << endl;
	while(seq[i] < seq[end])++i;
	int j = i;
	while(j < end){
		if(seq[j] < seq[end])return false;
         ++j;
	}
	return isPostOrder(seq,start,i-1) && isPostOrder(seq,i,end-1);
}
bool postOrder(vector<int> &seq){
	if(seq.size() <= 2)return true;
	return isPostOrder(seq,0,seq.size()-1);
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
// ====================测试代码====================
void Test(const char* testName, vector<int> sequence, int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(postOrder(sequence) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    vector<int> data = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    vector<int> data = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
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
void Test3()
{
    vector<int> data = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
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
void Test4()
{
    vector<int> data = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// 树中只有1个结点
void Test5()
{
    vector<int> data = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
    vector<int> data = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
    vector<int> data = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
    Test("Test8", vector<int>(), 0, true);
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

    return 0;
}

