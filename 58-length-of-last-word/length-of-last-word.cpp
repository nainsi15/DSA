class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int len =0;
        
        for(int i = n-1; i >= 1; i--){
            if(s[i] == ' ' && len == 0){
                continue;
            }
            else if(s[i] != ' ' && s[i-1] != ' '){
                len++;
            }
            else{
                break;
            }
        }
        return len+1;
    }
};