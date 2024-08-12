// https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0

// Topo Sort can be used a graph is a DAG and topo sort ensures that if u comes before v, resolve everything related to u 
// then move to v that too eficiently


// User function Template for C++
class Solution {
  public:
  
     void topoSort(vector<pair<int,int>> adj[], stack<int>&st, int src, vector<bool>&visited){
        visited[src] = true;
        
        for(auto it: adj[src]){
            int node = it.first;
            if(visited[node] == false){
                topoSort(adj, st, node, visited);
            }
        }
        st.push(src);
     }
     
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int,int>>adj[N];
        
        for(int i = 0; i < M; i++){
           int u = edges[i][0];
           int v = edges[i][1];
           int wt = edges[i][2];
           adj[u].push_back({v, wt});
        }
        
        stack<int>st;
        vector<bool>visited(N, false);
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                topoSort(adj, st, i, visited);
            }
        }
        
        vector<int>dist(N, INT_MAX);
        dist[0] = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if (dist[node] != INT_MAX) { // Process only if the node is reachable
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        }
         for(auto &d : dist){
            if(d == INT_MAX) d = -1;
         }
            
        return dist;
    }
};
