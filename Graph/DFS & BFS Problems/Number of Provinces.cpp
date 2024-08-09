// https://leetcode.com/problems/number-of-provinces/

class Solution {
public:
    void dfs(int i,vector<int>&vis,vector<vector<int>>isConnected)
    {
        vis[i]=1;
        for(int it=0;it<isConnected.size();it++)
        {
            if(isConnected[i][it]==1 && !vis[it])
            {
                dfs(it,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                count++;
                dfs(i,vis,isConnected);
            }
        }
        return count; 
    }
};




/// GFG Adjancency matrix into adjacency list

    void dfs(vector<int>ad[], vector<bool>&visited, int src){
        visited[src] = true;
        
        for(auto it: ad[src]){
            if(visited[it] == false){
                dfs(ad, visited, it);
            }
        }
        
    }


    int numProvinces(vector<vector<int>> adj, int V) {
        
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
