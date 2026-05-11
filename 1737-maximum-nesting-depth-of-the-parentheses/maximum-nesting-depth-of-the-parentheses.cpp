class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int maxdepth = 0, depth = 0;

        for(char ch : s){
            if(ch == '('){
                depth++;
                maxdepth = max(maxdepth, depth);
            }
            else if(ch == ')'){
                depth--;
            }
        }
        return  maxdepth;
    }
};