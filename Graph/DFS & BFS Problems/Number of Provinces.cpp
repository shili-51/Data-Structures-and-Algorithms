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
