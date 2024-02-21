//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) 
    {
         int n = grid.size();
    int m = grid[0].size();
    
    queue<pair<int,pair<int,int>>> q;
    
    int sr = source.first;
    int sc = source.second;
    
    int dr = destination.first;
    int dc = destination.second;
    
    if(sr == dr && sc == dc) {
        return 0;
    }
    
    q.push({0, {sr, sc}});
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};
    
    while(!q.empty()) {
        int d = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                visited[nrow][ncol] = true;
                if(nrow == dr && ncol == dc) {
                    return d + 1;
                }
                q.push({d + 1, {nrow, ncol}});
            }
        }
    }
    return -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends