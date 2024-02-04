//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#include<stack>
#include<algorithm>
#include<bits/stdc++.h>
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int>st;
        
        for(int i=0; i<S.size(); i++)
        {
            if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/')
            {
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                
                if(S[i]=='+')
                {
                    st.push(num1+num2);
                }
                else if(S[i]=='-')
                {
                    st.push(num1-num2);
                }
                else if(S[i]=='*')
                {
                    st.push(num1*num2);
                }
                else if(S[i]=='/')
                {
                    st.push(num1/num2);
                }
            }
            else{
                int data = S[i]-'0';
                st.push(data);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends