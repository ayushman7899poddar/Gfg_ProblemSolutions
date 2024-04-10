//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int findSingle(int n, int arr[])
    {
        // int ans=0;
        // unordered_map<int,int>mp;
        
        // for(int i=0; i<n; i++)
        // {
        //     mp[arr[i]]++;
        //     if(mp[arr[i]] ==2)
        //     {
        //         mp[arr[i]]--;
        //         mp[arr[i]]--;
        //     }
        // }
        
        // for(auto i : mp)
        // {
        //     if(i.second %2 !=0 )
        //     {
        //         return i.first;
        //     }
        // }
        
        int ans=arr[0];
        for(int i=1; i<n; i++)
        {
            ans = ans^arr[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.findSingle(N, arr) << endl;
    }
    return 0; 
} 
// } Driver Code Ends