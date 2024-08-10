https://leetcode.com/problems/01-matrix/

// previous step distance from 0 will help to calculate future step distance


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<bool>>visited(row, vector<bool>(col, false));
        vector<vector<int>>dist(row, vector<int>(col, 0));
        queue<pair<pair<int,int>,int>>q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(mat[i][j] == 0){ 
                    q.push({{i,j},0}); 
                    visited[i][j] = true;
                }
            }
        }

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        while(q.empty() == false){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            dist[x][y] = steps;
            q.pop();
            
            // checking for 0 in neighbourers
            for(int i = 0; i < 4; i++){
                int currx = x + dx[i];
                int curry = y + dy[i];

                if(currx >= 0 && currx < row && curry >=0 && curry < col && visited[currx][curry] == false){
                    q.push({{currx,curry},steps + 1});
                    visited[currx][curry] = true;
                }
            }
        }

        return dist;
        
    }
};
