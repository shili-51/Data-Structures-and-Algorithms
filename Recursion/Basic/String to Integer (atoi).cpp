// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int len = s.length();
        int sign = 1;
        double num = 0;

        while(i < len && s[i] == ' ') i++;

        if(s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(s[i] == '+') i++;

        while(i < len && s[i] - '0' >= 0 && s[i] - '0' <= 9){
            num = (num*10) + (s[i] - '0');
            i++;
        }
        

        if(sign == -1) num = sign*num;
        num = (num > INT_MAX) ? INT_MAX : num;
        num = (num < INT_MIN) ? INT_MIN : num;
        return int(num);
    }
};
