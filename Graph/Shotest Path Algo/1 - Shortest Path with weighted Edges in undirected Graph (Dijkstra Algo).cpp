// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

// priority queue for considering shortest distance each time checking for neighbouring nodes - not the optimised One


vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dist(V, INT_MAX);
        dist[S] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        pq.push({0, S});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int edgeWeight = it[1];
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        return dist;
