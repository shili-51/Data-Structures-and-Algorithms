// for minimum area : area = min(area, height[ele] * (nextSmallerEle - prevSmallerEle - 1));

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // nse - next smaller element
        // pse - previous smaller element
        // area at any ith index = heights[i] * (nse - pse - 1);
        int maxArea = 0;
        int n = heights.size();
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                int ele = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = (st.empty()) ? -1 : st.top();
                // calculate area when we get dip (get nse)
                maxArea = max(maxArea, ele * (nse - pse - 1));
            }
            // keep on pushing elements till elements are increasing
            // as we cant comment on nse
            st.push(i);
        }
        while(!st.empty()){
            // for elements remaining in stack there is no nse
            int currElement = heights[st.top()];
            st.pop();
            int nse = n;
            int pse = (st.empty()) ? -1 : st.top();
            maxArea = max(maxArea, currElement * (nse - pse - 1));
        }
        return maxArea;
        
    }
};
