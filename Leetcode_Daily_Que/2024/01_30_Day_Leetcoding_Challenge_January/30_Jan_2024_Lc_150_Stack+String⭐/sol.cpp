// TC=O(N)
// SC=O(N)
class Solution {
public:
    int helper(int a,int b, string sign)
    {
        if(sign=="+") return a+b;
        else if (sign=="-") return a-b;
        else if (sign=="*") return a*b;
        else return a/b;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;

        for(int i=0;i<tokens.size();i++)
        {
            string curr=tokens[i];
            
            // As this is a string and its size can be  greater than 1. so if size is 1 , and its ascii value is less than 48, it definitely means it is an operator.
            if((curr.size()==1 )&& (curr[0]<48))
            {
                // it means the current character is operator
                
                int n2=(s.top()); s.pop();
              
                int n1=(s.top()); s.pop();
                
                int temp=helper(n1,n2,curr);
                s.push(temp);
            }
            else 
            {
                s.push(stoi(curr));
            }       
        }
           return (s.top());
    }
};