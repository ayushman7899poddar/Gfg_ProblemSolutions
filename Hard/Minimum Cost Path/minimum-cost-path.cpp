//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        int sum=0;
        
        
        
        vector<vector<int>>cost(n,vector<int>(m,1e9));
        
        cost[0][0]=grid[0][0];
        
        //min-heap:
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, 
            greater<pair<int,pair<int,int>>>> pq;
        
        pq.push({cost[0][0],{0,0}});
        
        // vector<vector<int>>vis(n,vector<int>(m,1e9));
        // vis[0][0]=1;
        
        
        
        int X=n-1, Y=m-1;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        
        while(!pq.empty())
        {
            int value = pq.top().first;
            
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
        
            for(int i=0; i<4; i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    if(value + grid[nrow][ncol] < cost[nrow][ncol])
                    {
                        cost[nrow][ncol] = value + grid[nrow][ncol];
                        pq.push({cost[nrow][ncol],{nrow,ncol}});
                        // vis[nrow][ncol]=1;
                    }
                }
            }
        }
        
        return cost[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends