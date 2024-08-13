
// Bellman ford can be applied on both directed and undirected graph

    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V, 100000000);
        dist[S] = 0;
        
        for(int i = 0; i < V-1; i++){
            for(auto it: edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] != 100000000 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // in Vth iteration if there is negative cycle 
        // dist array will get modified
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
                
            if(dist[u] != 100000000 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        
        return dist;
    }
