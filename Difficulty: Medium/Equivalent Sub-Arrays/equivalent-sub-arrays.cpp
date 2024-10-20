//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int solved(int arr[], int n, int k)
    {
        int i=0,j=0;
        // int n = arr.size();
        int cnt = 0;
        
        if(k==0) return 0;
        
        unordered_map<int,int>mp;
        
        while(j<n)
        {
            mp[arr[j]]++;
            
            while(mp.size() > k)
            {
                mp[arr[i]]--;
                if(mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
            cnt+=j-i+1;
            j++;
        }
        return cnt;
    }
    
    int countDistinctSubarray(int arr[], int n)
    {
        set<int>st;
        for(int i=0; i<n; i++)
        {
            st.insert(arr[i]);
        }
        
        int k = st.size();
        
        int ans = solved(arr,n,k) - solved(arr,n,k-1);
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends