//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include<queue>

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) 
    {
        long long mod = 100000 ;
        queue<pair<int,int>>q;
        
        vector<int>dist(mod,1e9);
        
        q.push({0,start});
        dist[start]=0;
        
        while(!q.empty())
        {
            int steps = q.front().first;
            int num = q.front().second;
            q.pop();
            
            if(num==end)
            {
                return steps;
            }
            
            for(int i=0; i<arr.size(); i++)
            {
                int temp = (num*arr[i])%mod;
                
                if(steps+1 < dist[temp])
                {
                    dist[temp]=steps+1;
                    q.push({steps+1,temp});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends