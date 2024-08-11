// https://leetcode.com/problems/course-schedule-ii/

// first complete all course with 0 dependency and then go on completing other courses 
// which rely on completion of courses in previous step - topological sort

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(int i = 0; i < prerequisites.size(); i++){
            for(int j = 0; j < prerequisites[i].size(); j++){
                int secondTask = prerequisites[i][0];
                int firstTask = prerequisites[i][1];
                adj[firstTask].push_back(secondTask);
                indegree[secondTask]++;
            }
        }

        queue<int>q;
        vector<int>order;
        
        for(int i = 0; i < adj.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(q.empty() == false){
            int currTask = q.front();
            q.pop();

            order.push_back(currTask);

            // traverse the dependency task of currTask
            for(auto it: adj[currTask]){
                indegree[it]--; //reduce currentTask dependency on adjacent
                if(indegree[it] == 0){
                    q.push(it);  // if this is the next task to be completed
                }
            }
        }

        // If the order contains all the courses, return it; otherwise, return an empty vector.
        return order.size() == numCourses ? order : vector<int>();
    }
};
