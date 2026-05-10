class Solution {
public:
    string removeOuterParentheses(string s) {
        // to store the string
        string result;
        int count = 0;

        for(int i = 0 ; i < s.size(); i++){
            if(s[i] == '('){
                //if counter is greater than 0 , it means this '(' is not an 
                //outermost paranthesis
                if(count > 0){
                    //add to the result
                    result += s[i];
                }
                count++;
            }
            else{
                //Decrease the balance for ')'
                count--;
                // If balance is greater than 0, it means this ')' is not an
                // outermost parenthesis
                if(count > 0){
                    // add to the answer
                    result += s[i];
                }
                
            }
        }
        return result;
    }
};