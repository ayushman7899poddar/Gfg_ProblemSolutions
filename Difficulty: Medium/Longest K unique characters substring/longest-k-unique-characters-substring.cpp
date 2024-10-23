//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // int solved(string s, int k)
    // {
    //     int cnt=0;
    //     int n = s.size();
    //     int i=0,j=0;
    //     unordered_map<char,int>mp;
        
    //     while(j<n)
    //     {
    //         mp[s[j]]++;
            
    //         while(mp[s[j]] > k)
    //         {
    //             mp[s[i]]--;
    //             if(mp[s[i]] == 0)
    //             {
    //                 mp.erase(s[i]);
    //             }
    //             i++;
    //         }
    //         cnt+=j-i+1;
    //         j++;
    //     }
    //     return cnt;
    // }
    
    int longestKSubstr(string s, int k) 
    {
        // int ans = solved(s,k) - solved(s,k-1);
        // return ans;
        
        int n = s.size();
    int l = 0;   int r = 0;
    
    int maxLen = -1;
    
    map<char,int> mpp;
    
    while(r < n){
        mpp[s[r]]++;
        
        if(mpp.size() > k){
            mpp[s[l]]--;
            if(mpp[s[l]] == 0){
                mpp.erase(s[l]);
            }
            l++;
        }
        
        if(mpp.size() == k){
            maxLen = max(maxLen, r-l+1);
        }
        r++;
    }
    return maxLen;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends