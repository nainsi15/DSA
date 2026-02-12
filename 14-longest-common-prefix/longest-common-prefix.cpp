class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
int n = strs.size();
        sort (strs.begin(), strs.end());
        string ans = "";
        string first = strs[0];
        string last = strs[n-1];

        int min_length = min(first.size(), last.size());
        for(int i = 0 ; i < min_length ; i++){
            if(first[i] != last[i]){
                return ans;
            }
            else{
               ans.push_back(first[i]);
            }
        }
        return ans;
    }
};