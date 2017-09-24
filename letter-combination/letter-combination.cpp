vector<string> letterCombinations(string digits) {
    string keyMap[]={""      ,      "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    //                              1     2     3      4     5     6      7    8    9
    char *charDic = new char(digits.size()+1);
    int *curP   = new int(digits.size());
    int *lastP  = new int(digits.size());
    int *lenP   = new int(digits.size());
    bool *flagP = new bool(digits.size()+1);
    charDic[digits.size()]='\0';
    for(int i=0;i<digits.size();i++)
    {
        curP[i]=0;
        lenP[i]=keyMap[digits[i]-'0'].size();
        flagP[i]=false;
        lastP[i]=0;
    }
    flagP[0]=true;
    int rounds=1;
    for(int i=0;i<digits.size();i++)
        rounds*=keyMap[digits[i]-'0'].size();
    vector<string> result(rounds);
    for(int r=0;r<rounds;r++)
    {
        for(int i=0;i<digits.size();i++)
        {
            charDic[i] = keyMap[digits[i]-'0'][curP[i]];
            if(flagP[i]==true)
            {
                curP[i]=(curP[i]+1)%lenP[i];//进位+1
                if(i!=0)flagP[i]=false;//设置进位标记为false
            }
            if(lastP[i]==lenP[i]-1 && curP[i]==0)
                flagP[i+1]=true;
            lastP[i]=curP[i];
        }
        result[r]=string(charDic);
    }
    sort(begin(result),end(result));
    return result;
}