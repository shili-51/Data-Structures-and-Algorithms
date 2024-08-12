

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>dist(V, INT_MAX);
        dist[S] = 0;
        
        set<pair<int,int>>st;
        
        st.insert({0, S});
        
        while(!st.empty()){
            
            for(auto it: st){
                int dis = it.first;
                int node = it.second;
                st.erase({dis,node});
                
                for(auto it: adj[node]){
                    int adjNode = it[0];
                    int edgeWeight = it[1];
                    
                    if(dis + edgeWeight < dist[adjNode]){
                        
                        if(dist[adjNode] != INT_MAX){
                            st.erase({dist[adjNode], adjNode});
                        }
                        
                        dist[adjNode] = dis + edgeWeight;
                        st.insert({dist[adjNode], adjNode});
                    }
                }
                
            }
            
        }
        
        return dist;
        
    }
