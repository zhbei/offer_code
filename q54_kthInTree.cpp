#include <iostream>
#include <cstdio>

using namespace std;

struct BinaryTreeNode{
	int val;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

int helper(BinaryTreeNode* root,int &k);
BinaryTreeNode* findKth(BinaryTreeNode* root,int k){
	if(k < 0){
		return NULL;
	}
	return helper(root,k);
}

BinaryTreeNode* helper(BinaryTreeNode* root,int &k){
	if(root == NULL){
		return NULL;
	}
	BinaryTreeNode* result = helper(root->left,k);
	--k;
	if(result == NULL && k == 1)
		result = root;
	if(result == NULL)
		result = helper(root->right,k);
	return result;
}

