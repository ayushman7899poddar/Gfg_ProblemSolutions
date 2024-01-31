//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    bool bfs(int node,vector<int>adj[],int vis[])
    {
        vis[node] = 1;
        queue<pair<int,int>>q;
        
        q.push({node,-1});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto neighbour : adj[node])
            {
                if(!vis[neighbour])
                {
                    q.push({neighbour,node});
                    vis[neighbour] = 1;
                    
                }
                 else if(parent!=neighbour){
                        return true;
                    }
            }
        }
        return false;
    }
    
	int detectCycle(int V, vector<int>adj[])
	{
	    //using bfs:
	    int vis[V] = {0};
	    
	    for(int i=0; i<V; i++)
	    {
	        if(!vis[i])
	        {
	            if(bfs(i,adj,vis) == true)
	            {
	                return true;
	            }
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
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends