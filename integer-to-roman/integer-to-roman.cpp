/*
Problem Description:
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution {
public:
    string intToRoman(int num) {
        string Roman_1[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
    string Roman_10[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    string Roman_100[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    string Roman_1000[]={"","M","MM","MMM"};
    vector<vector<string> > Romans(4);
    Romans[0]=vector<string>(begin(Roman_1),end(Roman_1));
    Romans[1]=vector<string>(begin(Roman_10),end(Roman_10));
    Romans[2]=vector<string>(begin(Roman_100),end(Roman_100));
    Romans[3]=vector<string>(begin(Roman_1000),end(Roman_1000));

    vector<int> val;
    while(num!=0)
    {
        int n = num%10;
        val.push_back(n);
        num/=10;
    }
    string result="";
    for(int i=val.size()-1;i>=0;i--)
    {
        result+=Romans[i][val[i]];
    }
    return result;
    }
};