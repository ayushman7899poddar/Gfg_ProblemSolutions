//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node,vector<pair<int,int>>adj[],int vis[],int pathVis[])
    {
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;
            
            if(!vis[v])
            {
                if(dfs(v,adj,vis,pathVis) == true )
                {
                    return true;
                }
            }
            else if(pathVis[v] && wt<0)
            {
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
    
	int isNegativeWeightCycle(int n, vector<vector<int>>edges)
	{
	    vector<pair<int,int>>adj[n];
	    
	    for(int i=0; i<edges.size(); i++)
	    {
	        int u = edges[i][0];
	        int v = edges[i][1];
	        int wt = edges[i][2];
	        
	        adj[u].push_back({v,wt});
	    }
	    
	    int vis[n]={0};
	    int pathVis[n]={0};
	    
	    for(int i=0; i<n; i++)
	    {
	        if(dfs(i,adj,vis,pathVis)==true)
	        {
	            return true;
	        }
	    }
	    return false;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends