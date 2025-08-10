class Solution {
public:
void func(int open , int close, string s, int n ,vector<string>& ans){
    if( open > n){
        return ;
    }
    if(open + close == 2 * n && open == close){
        ans.push_back(s);
        return;
    }
    if(open < n){
        func(open + 1, close, s +'(', n , ans);
    }
    if(close < open){
        func(open, close + 1, s +')', n , ans);
    }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        func(0, 0 , "", n , ans);
        return ans;
    }
};