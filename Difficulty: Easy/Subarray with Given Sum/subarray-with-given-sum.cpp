//{ Driver Code Starts
// Initial Template for C++
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#include<algorithm>
#include<cmath>

class Solution {
  public:
    
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>& arr, int sum) 
    {
         int value = 0;
    int i = 0, j = 0;
    int n = arr.size();
    vector<int> vec;

    while (j < n) 
    {
        value += arr[j];  // Add the current element to the window

        // Shrink the window from the left if the sum exceeds the target
        while (value > sum && i < j) 
        {
            value -= arr[i];
            i++;
        }

        // If we find the target sum, store the 1-based index range
        if (value == sum) 
        {
            vec.push_back(i + 1);  // 1-based index for start
            vec.push_back(j + 1);  // 1-based index for end
            return vec;            // Assuming only one subarray is required
        }

        j++;  // Expand the window to the right
    }

    return vec;  // Return an empty vector if no subarray found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int sum;
        cin >> sum;
        cin.ignore();

        Solution sln;
        vector<int> list = sln.subarraySum(arr, sum);
        if (list.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : list)
                cout << i << " ";
            cout << endl;
        }
    }

    return 0;
}

// } Driver Code Ends