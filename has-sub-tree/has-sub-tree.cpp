bool HasSubTreeHelper(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if(pRoot2==NULL)
        return true;
    else if((pRoot1!=NULL && pRoot2!=NULL))
    {
        if(pRoot1->val ==pRoot2->val)
            return HasSubTreeHelper(pRoot1->left,pRoot2->left)&&HasSubTreeHelper(pRoot1->right,pRoot2->right)||(HasSubTreeHelper(pRoot1->left,pRoot2)||HasSubTreeHelper(pRoot1->right,pRoot2));
        else 
            return HasSubTreeHelper(pRoot1->left,pRoot2)||HasSubTreeHelper(pRoot1->right,pRoot2);
    }
    else 
        return false;
}

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if(pRoot2 == NULL)return false;
    return HasSubTreeHelper(pRoot1,pRoot2);
}