//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k)
    {
        unordered_map<char,int>mp;
        for(auto i:s)
        {
            mp[i]++;
        }
        
        priority_queue<pair<int,char>>pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        
        while(k>0)
        {
            int times = pq.top().first-1;
            char key = pq.top().second;
            pq.pop();
            
            k--;
            pq.push({times,key});
        }
        
        int sum=0;
        while(!pq.empty())
        {
            int node = pq.top().first;
            pq.pop();
            
            sum+=node*node;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends