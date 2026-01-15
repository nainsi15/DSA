class Solution {
public:
    string largestOddNumber(string num) {
        int  j =-1;
        //traversing from back
       for(int i = num.size()-1; i >= 0; i--){
        //string to integer and then odd no. check
        if((num[i] - '0' )% 2 == 1){
            j = i;
            break;
        }
       }
       if(j == -1){
        return "";
       }
        // Skipping any leading zeroes
       int i = 0 ;
       while(i < num.size()){
        //found the starting non-zero number 
        if(num[i] != '0' ) break;
        i++;
       }
       //returning largest odd string
       return num.substr(i, j-i+1);
    }
};