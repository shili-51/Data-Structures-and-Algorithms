// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long int power = n;
        if(n < 0) power = -1*power;
        while(power > 0){
            if(power % 2 == 1){
                ans = ans * x;
                power = power - 1;
            }else{
                x = x * x;
                power = power/2;
            }
        }
        if(n < 0) return (double)(((double) (1))/((double)(ans)));
        else return ans;
    }
};
