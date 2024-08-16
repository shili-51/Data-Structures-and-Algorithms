
// greedy approach to consider nodes with minimum weight first

    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>visited(V,false);
        pq.push({0,0});
        
        int sum = 0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(visited[node] == true) continue;
            visited[node] = true;
            sum += wt;
            
            for(auto it: adj[node]){
                int adjNode = it[0];
                int adjNodewt = it[1];
                
                if(visited[adjNode] == false){
                    pq.push({adjNodewt, adjNode});
                }
            }
        }
        return sum;
    }
