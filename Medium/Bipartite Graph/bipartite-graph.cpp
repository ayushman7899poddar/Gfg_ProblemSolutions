//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    private:
    bool check(int start, int V, vector<int>adj[], int color[])
    {
        queue<int>q;
        q.push(start);
        
        color[start]=0;
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto it:adj[node])
            {
                // IF THE ADJACENT NODE IS NOT YET COLORED YOU WILL GIVE THE
                // OPPOSITE COLOR OF THE NODE:
                if(color[it] == -1)
                {
                    color[it]=!color[node];
                    q.push(it);
                }
                // IS THE ADJACENT HAVING SAME COLOR SOMEONE DID COLOR
                // IT ON THE SAME PATH:
                else if(color[it] == color[node])
                {
                    return false;
                    
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[])
	{
	    // make a color array with vertices size
	    int color[V];
	    // initially every vertices color is -1
	    for(int i=0; i<V; i++)
	    {
	        color[i]=-1;
	    }
	    
	    for(int i=0; i<V; i++)
	    {
	        if(color[i]==-1){
	            if(check(i,V,adj,color)==false){
	                return false;
	            }
	        }
	    }
	    return true;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends