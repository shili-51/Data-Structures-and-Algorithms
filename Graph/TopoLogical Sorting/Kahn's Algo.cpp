// https://www.geeksforgeeks.org/problems/topological-sort/1

// Topo Sort using BFS

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>indegree(V,0);
	    
	    for(int i = 0; i < V; i++){
	        for(auto it: adj[i]){
	            indegree[it]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i = 0; i < indegree.size(); i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int>topoSort;
	    while(q.empty() == false){
	        int curr = q.front();
	        topoSort.push_back(curr);
	        q.pop();
	        
	       // traverse adjacents
	       for(auto it: adj[curr]){
	           indegree[it]--;
	           if(indegree[it] == 0){
	               q.push(it);
	           }
	       }
	    }
	    return topoSort;
	}
