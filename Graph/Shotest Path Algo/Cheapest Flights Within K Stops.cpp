// dijkstra can we applied on both directed and undirected graph

    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        
        //dijkstra 
        
        int row = flights.size();
        int col = flights[0].size();

        vector<pair<int,int>>adj[n];

        for(int i = 0; i < row; i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            adj[u].push_back({v, cost});
        }



        queue<pair<int, pair<int,int>>>q;
        vector<int>dist(n, INT_MAX);
        // {stops, {node, distance}}
        q.push({0, {src, 0}});
        dist[src] = 0;

        while(!q.empty()){
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            for(auto it: adj[node]){
                int adjNode = it.first;
                int adjcost = it.second;
                if(stops <= k && cost + adjcost < dist[adjNode]){
                    dist[adjNode] = cost + adjcost;
                    q.push({stops + 1, {adjNode, cost + adjcost}});
                }
            }

        }

        if(dist[dst] == INT_MAX) return -1;
        else return dist[dst];
