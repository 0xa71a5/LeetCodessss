/*
Problem Describtion:
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are+,-,*,/. Each operand may be an integer or another expression.
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/


class Solution {
public:
    int evalRPN(vector<string> &tokens) {
       stack<int> num;     
       for(int i=0;i<tokens.size();i++)
       {
           if(!(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"))
           {
               int number=atoi(tokens[i].c_str());
               num.push(number);
           }
           else
           {
               int right=num.top();num.pop();
               int left=num.top();num.pop();
               if(tokens[i]=="+")
                   num.push(left+right);
               else if(tokens[i]=="-")
                   num.push(left-right);
               else if(tokens[i]=="*")
                   num.push(left*right);
               else if(tokens[i]=="/")
                   num.push(left/right);
           }
       }
       return num.top();
    }
};