class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int end = s.find_last_not_of(' ');
        int pos = s.find_last_of(' ', end)+1; 
        int len =0;
        int i = pos;
        while(i <= end){
            len++;
            i++;
        }
        
        return len;
    }
};