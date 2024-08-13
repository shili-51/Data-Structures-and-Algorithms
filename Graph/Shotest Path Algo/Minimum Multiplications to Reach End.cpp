// consider array elements as weights and product of each node with each array element as new adjacent nodes

// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<int>q;
        // {steps, node}
        q.push(start);
        vector<int>dist(100000, INT_MAX);
        dist[start] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int i = 0; i < arr.size(); i++){
                int nextNode = (node * arr[i]) % 100000;
                
                if(dist[nextNode] > dist[node] + 1){
                    dist[nextNode] = dist[node] + 1;
                    // if(nextNode == end) return dist[nextNode];
                    q.push(nextNode);
                }
            }
        }
        
        return dist[end] == INT_MAX ? -1 : dist[end];
    }
};
