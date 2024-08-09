// https://www.geeksforgeeks.org/problems/number-of-provinces/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-provinces

class Solution {
    
  private:
    void dfs(vector<int>ad[], vector<bool>&visited, int src){
        visited[src] = true;
        
        for(auto it: ad[src]){
            if(visited[it] == false){
                dfs(ad, visited, it);
            }
        }
        
    }
    
  public:
    int numProvinces(vector<vector<int>> adj, int V) {

      // conversion of matrix into adjacency list
        vector<int>ad[V];
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1 && i != j){
                    ad[i].push_back(j);
                    ad[j].push_back(i);
                }
            }
        }
        
        
        // code here
        vector<bool>visited(V, false);
        int provinces = 0;
        for(int i = 0; i < V; i++){
            if(visited[i] == false){
                provinces++;
                dfs(ad, visited, i);
            }
        }
        return provinces;
    }
};
