// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0, ans = 0;
        int n = cardPoints.size();
        for(int j = 0; j < k; j++){
             lsum += cardPoints[j];
        }
        ans = lsum;
        int rightIndex = n - 1;
        for(int i = k - 1; i >= 0; i--){
            lsum = lsum - cardPoints[i];
            rsum = rsum + cardPoints[rightIndex];
            ans = max(ans, lsum + rsum);
            rightIndex--;
        }
        return ans;
    }
};
