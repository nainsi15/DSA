class Solution {
public:
void func(int ind, string digits, string s, vector<string> &ans, string combo[] ){
    if( ind == digits.size()){
        ans.push_back(s);
        return;
    }
    int digit = digits[ind] - '0';

    for(int i = 0; i < combo[digit].size(); i++){
        func(ind + 1, digits, s + combo[digit][i], ans, combo);
    }
}
    vector<string> letterCombinations(string digits) {
          if (digits.empty()) return {};
         string combo[] = {"", "", "abc", "def", "ghi", "jkl" , "mno" , "pqrs" ,"tuv", "wxyz"};
        vector<string> ans;
        string s = "";
        func( 0, digits, s, ans, combo);
        return ans;
    }
};