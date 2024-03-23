//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) 
    {
       vector<int>dp(n+1,-1);
       
       dp[0]=0;
       dp[1]=1;
       
       if(n==0){
           return {0};
       }
       if(n==1){
           return {0,1};
       }
       vector<int>vec;
       vec.push_back(0);
       vec.push_back(1);
       
       long long int mod = 1e9+7;
       for(int i=2; i<=n; i++)
       {
           dp[i] = dp[i-1]%mod + dp[i-2]%mod;
           dp[i] = dp[i]%mod;
           vec.push_back(dp[i]);
       }
       return vec;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends