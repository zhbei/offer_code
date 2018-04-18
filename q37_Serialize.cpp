#include <iostream>
#include <fstream>
#include <cstdio>
#include <ostream>

using namespace std;

struct BinaryTreeNode
{	
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};
void serialize(const BinaryTreeNode* root,ostream &stream){
    if(root == NULL){
        stream << "#" <<",";
        return;
    }
    stream << root->val << ",";
    serialize(root->left,stream);
    serialize(root->right,stream);
}
bool readNumber(istream& stream,int& number){
    char buf[11];
    if(stream.get(buf,10,',')){
        stream.ignore(10,',');
        if(buf[0] != '#'){
            number = 0;
            int i = 0;
            while(i < 11 && buf[i] != '\0'){
                number = number * 10 + buf[i++] - '0';
            }
            return true;
        }else{
            return false;        
        }
    }
    return false;
}
void deSerialize(BinaryTreeNode* & root ,istream& stream){
    int number;
    if(readNumber(stream,number)){
        root = new BinaryTreeNode();
        root->val = number;
        root->left = NULL;
        root->right = NULL;
        deSerialize(root->left,stream);
        deSerialize(root->right,stream);
    }
}
// ====================测试代码====================
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
// ==================== Test Code ====================
bool isSameTree(const BinaryTreeNode* pRoot1, const BinaryTreeNode* pRoot2)
{
    if(pRoot1 == nullptr && pRoot2 == nullptr)
        return true;

    if(pRoot1 == nullptr || pRoot2 == nullptr)
        return false;

    if(pRoot1->val != pRoot2->val)
        return false;

    return isSameTree(pRoot1->left, pRoot2->left) &&
        isSameTree(pRoot1->right, pRoot2->right);
}
void Test(const char* testName, BinaryTreeNode* pRoot)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    PrintTree(pRoot);

    const char* fileName = "test.txt";
    ofstream fileOut;
    fileOut.open(fileName);

    serialize(pRoot, fileOut);
    fileOut.close();

    // print the serialized file
    ifstream fileIn1;
    char ch;
    fileIn1.open(fileName);
    while(!fileIn1.eof())
    {
        fileIn1 >> ch;
        cout << ch;
    }
    fileIn1.close();
    cout << endl;

    ifstream fileIn2;
    fileIn2.open(fileName);
    BinaryTreeNode* pNewRoot = nullptr;
    deSerialize(pNewRoot, fileIn2);
    fileIn2.close();

    PrintTree(pNewRoot);

    if(isSameTree(pRoot, pNewRoot))
        printf("The deserialized tree is same as the oritinal tree.\n\n");
    else
        printf("The deserialized tree is NOT same as the oritinal tree.\n\n");

    DestroyTree(pNewRoot);
}

//            8
//        6      10
//       5 7    9  11
void Test1()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test("Test1", pNode8);

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

    Test("Test2", pNode5);

    DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test3()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode2);

    Test("Test3", pNode5);

    DestroyTree(pNode5);
}

void Test4()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    Test("Test4", pNode5);

    DestroyTree(pNode5);
}

void Test5()
{
    Test("Test5", nullptr);
}

//        5
//         5
//          5
//         5
//        5
//       5 5
//      5   5
void Test6()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode61 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode62 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode71 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode72 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode5, nullptr);
    ConnectTreeNodes(pNode5, pNode61, pNode62);
    ConnectTreeNodes(pNode61, pNode71, nullptr);
    ConnectTreeNodes(pNode62, nullptr, pNode72);

    Test("Test6", pNode1);

    DestroyTree(pNode1);
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