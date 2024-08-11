// https://www.geeksforgeeks.org/problems/number-of-distinct-islands/0

// store each path cordinates in Set such that (start point - curr cordinate) to keep track of same shape of islands

    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid, int row0, int col0, vector<pair<int,int>>&vec){
        
        int row = grid.size();
        int col = grid[0].size();
        
        visited[i][j] = true;
        vec.push_back({i - row0, j - col0});
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        for(int k = 0; k < 4; k++){
            int currx = i + dx[k];
            int curry = j + dy[k];
            if(currx >= 0 && currx < row && curry >= 0 && curry < col && grid[currx][curry] == 1 && visited[currx][curry] == false){
                dfs(currx, curry, visited, grid, row0, col0, vec);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int row = grid.size();
        int col = grid[0].size();
        set<vector<pair<int, int>>>st;
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(visited[i][j] == false && grid[i][j] == 1){
                    vector<pair<int,int>>vec;
                    dfs(i,j,visited,grid,i,j,vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
