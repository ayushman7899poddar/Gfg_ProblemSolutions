//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s)
    {
        int n = s.size();
        
        int num=0;
        if(s.size()<3)
        {
            num = stoi(s);
            if(num%8==0){
                return 1;
            }
        }
        else if(s.size()>=3)
        {
            num = num*10 +s[n-3];
            num = num*10+s[n-2];
            num = num*10 + s[n-1];
            
            if(num%8==0){
                return 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends