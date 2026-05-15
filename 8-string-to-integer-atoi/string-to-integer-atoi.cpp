class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        //case 1: Skip leading spaces 
        while(i < n && s[i] == ' '){
            i++;
        }

        //case 2: Determining the sign
        int sign = 1;
        if(i < n && s[i] == '-'){
            sign = -1;
            i++;
        }
        else if( i < n && s[i] == '+'){
            i++;
        }

        //case 3: Conversion and result
        long long result = 0;
        while(i < n && isdigit(s[i])){
            result = result * 10 + (s[i] - '0');
            i++;

            //checking for overflow condition
            if(result *sign >= INT_MAX){
                return INT_MAX;
            }
            if(result *sign <= INT_MIN){
                return INT_MIN;
            }
        }
        return result*sign;
        }
};