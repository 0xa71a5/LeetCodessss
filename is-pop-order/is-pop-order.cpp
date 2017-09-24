bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    stack<int> tStack;
    int p1=0,p2=0;
    int m=pushV.size(),n=popV.size();
    if(m!=n)return false;

    while(p2<n)
    {
        int target = popV[p2];
        if(tStack.size()!=0 && tStack.top()==target)
        {
            tStack.pop();
            p2++;
        }
        else
        {
            if(p1==m)return false;
            while(pushV[p1]!=target)
            {
                tStack.push(pushV[p1++]);
                if(p1==m)return false;
            }
            p1++;
            p2++;
        }
    }
    return true;
}