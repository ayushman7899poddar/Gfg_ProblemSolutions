//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) 
    {
        int n = height.size();
        
        if(n==0)
        {
            return 0;
        }
        
        int cnt=1;
        int ht = height[0];
        
        for(int i=1; i<height.size(); i++)
        {
            if(height[i]>ht)
            {
                cnt++;
                ht = height[i];
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends