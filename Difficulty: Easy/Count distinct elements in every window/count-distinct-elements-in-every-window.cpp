//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        unordered_map<int,int>mp;
        vector<int>vec;
        
        int i=0,j=0;
        int dis=0;
        
        
        while(j<n)
        {
            mp[A[j]]++;
            
            if(mp[A[j]] == 1)
            {
                dis++;
            }
            
            if(j-i+1 == k)
            {
                // cout<<"ele : "<<dis<<" ";
                vec.push_back(dis);
                
                if(mp[A[i]] == 1)
                {
                    dis--;
                    mp[A[i]]--;
                }
                else{
                    mp[A[i]]--;
                }
                i++;
            }
            j++;
        }
        // cout<<endl;
        return vec;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends