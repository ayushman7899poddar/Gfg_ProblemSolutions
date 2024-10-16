//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) 
    {
        int cnt=0;
        int n = S.size();
        unordered_map<char,int>mp;
        int distinctElement = 0;
        int i=0,j=0;
        
        
        while(j<n)
        {
            mp[S[j]]++;
            if(mp[S[j]] == 1)
            {
                distinctElement++;
            }
            
            if(j-i+1 == K)
            {
                if(distinctElement == K-1)
                {
                    cnt++;
                }
                
                if(mp[S[i]] == 1)
                {
                    distinctElement--;
                }
                mp[S[i]]--;
                i++;
            }
            j++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends