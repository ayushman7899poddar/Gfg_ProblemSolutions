//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) 
    {
        int num=0;
        
        if(str[0]!='-')
        {
            for(int i=0; i<str.size(); i++)
            {
                if((str[i]-'0')>=0 && (str[i]-'0')<=9)
                {
                    num=num*10+(str[i]-'0');
                }
                else
                {
                        return -1;
                }
               
            }
            return num;
            
        }
        else if(str[0]=='-')
        {
            for(int i=1; i<str.size(); i++)
            {
                if((str[i]-'0')>=0 && (str[i]-'0')<=9)
                {
                    num=num*10+(str[i]-'0');
                }
                else{
                        return -1;
                }
                
            }
             return -num;
        }
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends