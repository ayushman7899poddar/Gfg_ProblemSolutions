//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) 
    {
        
        unordered_map<int,int>mp;
        vector<int>ans;
        
        for(int i=0; i<arr.size(); i++)
        {
            mp[arr[i]]++;
            if(mp[arr[i]]==2)
            {
                ans.push_back(arr[i]);
            }
        }
        
        for(int i=0; i<arr.size(); i++)
        {
            if(mp.find(i+1) == mp.end())
            {
                ans.push_back(i+1);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends