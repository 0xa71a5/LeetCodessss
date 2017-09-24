
bool VerifySquenceOfBSTHelper(vector<int>& seq,int left,int right)
{   
    if(right-left<=1)return true;
    int root = seq[right];
    int i=left;
    for(;i<right;i++)
    {
        if(seq[i]>root)break;
    }
    int middle=i;
    for(;i<right;i++)
    {
        if(seq[i]<root)break;
    }
    if(i!=right)return false;
    return VerifySquenceOfBSTHelper(seq,left,middle-1)&&VerifySquenceOfBSTHelper(seq,middle,right-1);
}


bool VerifySquenceOfBST(vector<int> sequence) {
    return VerifySquenceOfBSTHelper(sequence,0,sequence.size()-1);
}