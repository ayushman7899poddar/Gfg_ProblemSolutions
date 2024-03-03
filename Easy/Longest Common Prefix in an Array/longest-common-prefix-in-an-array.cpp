//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
#include<algorithm>
#include<bits/stdc++.h>

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        int mini=INT_MAX;
        
        for(int i=0; i<N; i++)
        {
            int temp = arr[i].size();
            
            mini = min(mini,temp);
        }
        // cout<<mini<<endl;
        
        int i=0;
        string ans="";
        
        while(i<mini)
        {
            set<char>st;
            
            for(int j=0; j<N; j++)
            {
                st.insert(arr[j][i]);
            }
            if(st.size()>1)
            {
                break;
            }
            if(st.size()==1)
            {
                for(auto it : st)
                {
                    ans+=it;
                    // cout<<ans<<" ";
                }
            }
            i++;
        }
        // cout<<endl;
        if(ans.size()==0){
            return "-1";
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends