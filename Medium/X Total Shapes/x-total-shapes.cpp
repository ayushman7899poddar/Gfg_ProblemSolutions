//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
   void dfs( int row , int col , vector<vector<int>> &vis ,
        vector<vector<char>>& grid)
    {

        int n = grid.size();

        int m = grid[0].size();

        vis[row][col] = 1; 

        int delrow[4] = { -1,0,1,0};

        int delcol[4] ={ 0,1,0,-1};

        for( int i = 0 ; i < 4 ; i ++)

        {

            int nrow = row + delrow[i];

            int ncol = col +delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] &&  grid[nrow][ncol] == 'X')

            {

                dfs(nrow,ncol,vis,grid);

                vis[nrow][ncol] = 1;

            }

        }
    }
    int xShape(vector<vector<char>>& grid) 
    { 
          int counter = 0 ;

        int n = grid.size();

        int m = grid[0].size();

        vector<vector<int>> vis(n , vector<int>(m,0));

        for( int i = 0 ; i < n ; i ++)

        {

            for( int j = 0 ; j < m ; j ++)

            {

                if( grid[i][j] =='X' && !vis[i][j])

                {

                    counter++;

                    dfs(i,j,vis,grid);

                }

            }

        }

        return counter;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}
// } Driver Code Ends