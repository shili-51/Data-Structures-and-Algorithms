#include<bits/stdc++.h>
using namespace std;


vector<int> breadFirstSearch(vector<int>adj[], int nodes, int srcNode) {

      vector<int> bfs;
      queue<int>q;
      vector>bool>visited(nodes, false);
      q.push(srcNode);
      visited[srcNode] = true;
      

      while(q.empty() == false){
        int curr = q.front();
        q.pop();
        bfs.push_back(curr);

        // traversing neighbourers of curr
        for(auto it: adj[curr]){
          if(visited[it] == false){
            q.push(it);
            visited[it] = true;
          }
        }
      }
  
      return bfs;
} 


int main() {
       int nodes, edges;
       cin>>nodes>>edges;

      // making adjacency list to store graph
      vector<int>adj[nodes];

      for(int i = 0; i < edges; i++) {
          int u, v;
          cin>>u>>v;
          // undirected graph
         adj[u].push_back(v);
         adj[v].push_back(u);
      }
      int src = 0;
      vector<int>bfs = breadFirstSearch(adj, nodes, src);
      
      for(int i = 0; i < bfs.size(); i++){
          cout<<bfs[i]<<" "<<endl;
      }

}
