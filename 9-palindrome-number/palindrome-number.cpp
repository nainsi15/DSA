class Solution {
public:
    bool isPalindrome(int x) {
        if ( x< 0)
        return false; 

       int original_num = x;
       long long reverse_num = 0; 
       while( x > 0){
        int digit = x%10;
        reverse_num =  reverse_num* 10 + digit;
        x /= 10; 
       }
        if(original_num == reverse_num){
            return true;
        }
    return false;
    }
};