// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph

    bool dfs(int src, vector<int> adj[], vector<bool>&vis, int parent){
        vis[src] = true;
        for(auto it: adj[src]){
            if(vis[it] == false){
                if(dfs(it, adj, vis, src) == true) return true;
            }else if(vis[it] == true){
                if(parent != it){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>vis(V+1, false);
        for(int i = 0; i < V; i++){
            if(vis[i] == false){
                if(dfs(i,adj,vis,-1) == true){
                    return true;
                }
            }
        }
        return false;
    }
