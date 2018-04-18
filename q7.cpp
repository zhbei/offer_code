#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(){
		left = NULL;
		right = NULL;
	}
};

TreeNode* helper(vector<int> &preOrder,int ps,int pe,vector<int> &inOrder,int is,int ie){
	TreeNode *root = new TreeNode();
	root->val = preOrder[ps];
	if(is==ie && ps == pe && preOrder[ps] == inOrder[is]){
		root->left = root->right = NULL;
		return root;	
	}
	int i = is;
	while(i <= ie && inOrder[i] == preOrder[ps])
		++i;
	int j = ps + (i - is);
	if(i > is)
		root->left = helper(preOrder,ps+1,j,inOrder,is,i-1);
	if(i < ie)
		root->right = helper(preOrder,j+1,pe,inOrder,i+1,ie);
	return root;
}

TreeNode* rebuildTree(vector<int> &preOrder,vector<int> &inOrder){
	if(preOrder.size() <=0 || inOrder.size() <=0 || preOrder.size() != inOrder.size()){
		return NULL;
	}
	return helper(preOrder,0,preOrder.size() - 1,inOrder,0,inOrder.size() - 1);
}
void preT(TreeNode* root){
	if(root == NULL)return;
	cout << root->val << endl;
	preT(root->left);
	preT(root->right);
}
void inT(TreeNode* root){
	if(root == NULL)return;
	inT(root->left);
	cout << root->val << endl;
	inT(root->right);
}
void test(){
	vector<int> pre = {1,2,4,7,3,5,6,8};
	vector<int> in = {4,7,2,1,5,3,8,6};
	TreeNode *root = rebuildTree(pre,in);
	preT(root);
	cout << endl;
	inT(root);
}

int main(){
	test();
	return 0;
}