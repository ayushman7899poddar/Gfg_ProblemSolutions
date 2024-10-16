//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
//   bool isSorted(vector<int>&vec)
//   {
//       vector<int>temp(vec);
//       sort(vec.begin(),vec.end());
//       for(int i=0; i<vec.size(); i++)
//       {
//           if(vec[i]!=temp[i])
//           {
//               return false;
//           }
//       }
//       return true;
//   }
  
    bool checkSorted(vector<int> &arr) 
    {
        
        int count = 0;
        
        for(int i =0 ; i < arr.size(); i++){
            if(arr[i] != i+1) {
                int temp = arr[i];
                arr[i] = arr[temp-1];
                arr[temp-1] = temp;
                count++;
                i--;
            }
            if(count > 2) return false;
        }
        return (count == 0 || count == 2);
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends