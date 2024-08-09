// https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>>q;

        int freshOranges = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }

        if(freshOranges == 0) return 0;

        // traversing adjacent oranges at a time
        int time = 0;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        while(q.empty() == false){
            
            int sz = q.size();
            bool rotten = false;

            // rot all oranges on same level
            for(int k = 0; k < sz; k++){
                int currx = q.front().first;
                int curry = q.front().second;
                q.pop();
              
                // rotting all neighbour oranges
                for(int i = 0; i < 4; i++){
                    int x = currx + dx[i];
                    int y = curry + dy[i];
                    if(x >= 0 && x < row && y >= 0 && y < col && grid[x][y] == 1){
                       grid[x][y] = 2;
                       q.push({x,y});
                       freshOranges--;
                       rotten = true;  // if any orange is rotten then only increment time value
                    }
                }
            }
            if(rotten == true) time++;
        }

        if(freshOranges == 0) return time;
        else return -1;
        
    }
};
