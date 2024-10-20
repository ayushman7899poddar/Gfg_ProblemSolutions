//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) 
    {
        vector<int>vec;
        deque<int>dq;
        int i=0,j=0;
        
        
        while(j<n)
        {
            while(!dq.empty() && dq.back() < arr[j])
            {
                dq.pop_back();
            }
            
            dq.push_back(arr[j]);
            
            if(j-i+1 == k)
            {
                vec.push_back(dq.front());
                
                if(dq.front() == arr[i])
                {
                    dq.pop_front();
                }
                i++;
            }
            j++;
        }
        return vec;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends