// https://leetcode.com/problems/number-of-enclaves/

//starting from boundary try to visit all land cells, if some are left unvisited they form enclaves

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>visited(row,(vector<bool>(col, false)));

        queue<pair<int,int>>q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(i == 0 || i == row-1 || j == 0 || j == col-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        visited[i][j] = true;
                    }
                }
            }
        }
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(q.empty() == false){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int currx = x + dx[i];
                int curry = y + dy[i];
                if(currx >= 0 && currx < row && curry >= 0 && curry < col && grid[currx][curry] == 1 && visited[currx][curry] == false){
                   q.push({currx, curry});
                   visited[currx][curry] = true;
                }
            }
            
        }

        int enclaves = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1 && visited[i][j] == false){
                    enclaves++;
                }
            }
        }

        return enclaves;
    }
};
