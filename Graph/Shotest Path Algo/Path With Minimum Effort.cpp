// https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1

// dijkstra on maze

int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        // code here
        
        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        
        int row = heights.size();
        int col = heights[0].size();
        
        pq.push({0,{0,0}});
        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
        dist[0][0] = 0;
        
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            if(x == row - 1 && y == col - 1) return dis;
            
            for(int i = 0; i < 4; i++){
                int currx = x + dx[i];
                int curry = y + dy[i];
                
                if(currx >= 0 && currx < row && curry >= 0 && curry < col){
                    int route = max((abs(heights[x][y] - heights[currx][curry])), dis);
                    
                    if(route < dist[currx][curry]){
                        dist[currx][curry] = route;
                        pq.push({route, {currx, curry}});
                    }

                }
            }
        }
        return 0;
    }
