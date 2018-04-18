int TreeDepth(TreeNode* pRoot)
{
	if(pRoot == NULL){
		return 0;
	}
	int left = 1 + TreeDepth(pRoot->left);
	int right = 1 + TreeDepth(pRoot->right);
	return left > right ? left : right;
}