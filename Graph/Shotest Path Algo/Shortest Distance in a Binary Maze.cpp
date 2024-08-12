// https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1

    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>dist(row, vector<int>(col, INT_MAX));
        
        // {distance, {coordinate}}
        queue<pair<int,pair<int,int>>>q;
        q.push({0, {source.first, source.second}});
        dist[source.first][source.second] = 0;
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        while(!q.empty()){
            int dis = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            
            // traversing neighbourers
            for(int i = 0; i < 4; i++){
                int currx = x + dx[i];
                int curry = y + dy[i];
                
                if(currx >= 0 && currx < row && curry >= 0 && curry < col && grid[currx][curry] == 1){
                    if(dist[currx][curry] > 1 + dis){
                        dist[currx][curry] = 1 + dis;
                        q.push({dist[currx][curry], {currx, curry}});
                    }
                }
            }
        }
        if(dist[destination.first][destination.second] == INT_MAX) return -1;
        else return dist[destination.first][destination.second];
    }
