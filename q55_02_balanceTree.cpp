    bool IsBalanced_Solution(TreeNode* pRoot) {
        bool result = true;
        helper(pRoot,result);
        return result;
    }
    int helper(TreeNode* root,bool& balance){
        if(root == NULL)
            return NULL;
        int left = 0, right = 0;
        if(balance)
            left = 1 + helper(root->left,balance);
        if(balance)
            right = 1 + helper(root->right,balance);
        if(balance && abs(left - right) <= 1)
            balance = true;
        else{
            balance = false;
        }
        return max(left,right);
    }