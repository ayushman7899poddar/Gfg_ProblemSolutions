//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int rotateDelete(vector<int> &arr) 
    {
        
        int n = arr.size(); 
        int ptr = n/2;
        
        for(int k=1; k<=ptr; k++)
        {
           // Right rotate the array:
           int lastElement = arr.back();
           arr.pop_back();
           
           arr.insert(arr.begin(),lastElement);
           
           // int delete n-k+1 th element;
           int deleteIndex = arr.size()-k;
           
           arr.erase(arr.begin()+deleteIndex);
           
        }
        
        int ans = arr[0];
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends