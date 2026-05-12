class Solution {
public:
    string reverseWords(string s) {
         int n = s.size();
        reverse(s.begin(), s.end());
        string ans = "";

        for(int i = 0; i < n ; i++){
        //detecting each word
        string word = "";
            while(i < n && s[i] != ' '){
                word += s[i];
                i++;
        }
        //reversing each word
        reverse(word.begin(), word.end());
        if(word.length() > 0)
            ans += " " + word;
    }
    return ans.substr(1);
    }
};