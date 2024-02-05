//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        
        queue<pair<int,int>>q;
        
        int ansRow=-1,ansCol=-1;
        
        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(grid[row][col]==1)
                {
                    q.push({row,col});
                }
                else if(grid[row][col]==2)
                {
                    ansRow=row;
                    ansCol=col;
                }
            }
        }
        
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            // if(grid[row][col]==2)
            // {
            //     return true;
            // }
            if(row==ansRow && col==ansCol)
            {
                return true;
            }
            
            for(int i=0; i<4; i++)
            {
                int nrow = row+delRow[i];
                int ncol = col+delCol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && 
                (grid[nrow][ncol]==3 || grid[nrow][ncol]==2) )
                {
                    q.push({nrow,ncol});
                    // vis[nrow][ncol]=1;
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
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends