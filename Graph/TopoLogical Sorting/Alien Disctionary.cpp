// https://www.geeksforgeeks.org/problems/alien-dictionary/1

// compare adjacent string and on first mismatch, draw an edge and make DAG for implementing Topo Sort in order to get
// order of characters according to alien dictionary

    vector<int>topoSort(vector<int>adj[], int V){
        
        vector<int>topo;
        vector<int>indegree(V,0);
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
            
        }
        
        queue<int>q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        return topo;
    }
    
    string findOrder(string dict[], int N, int k) {
        //code here
        
        vector<int>adj[k];
        
        for(int i = 0; i < N - 1; i++){
            string s1 = dict[i];
            string s2 = dict[i + 1];
            
            int len1 = s1.size();
            int len2 = s2.size();
            int count = 0;
            for(int j = 0; j < min(len1,len2); j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
            }
        }
 
        
        // for order based on alien dictionary 
        // Topological Sorting
        
        vector<int>topo = topoSort(adj, k);
        
        string ans = "";
        
        for(auto it: topo){
            ans += char(it + 'a');
        }
        
        return ans;
    }
