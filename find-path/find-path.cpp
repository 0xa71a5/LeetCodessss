void FindPathHelper(TreeNode *root,vector<vector<int> >& vs,vector<int> &v,int expectNumber)
{
    if(root==NULL) return;
    v.push_back(root->val);
    if(root->val == expectNumber)
    {
        vs.push_back(v);
    }
    else{
        if(root->left!=NULL) 
            FindPathHelper(root->left,vs,v,expectNumber - root->val);
        if(root->right!=NULL)
            FindPathHelper(root->right,vs,v,expectNumber - root->val);
    }
    v.pop_back();
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    vector<vector<int> > vs;
    vector<int> v;
    FindPathHelper(root,vs,v,expectNumber);
    return vs;
}