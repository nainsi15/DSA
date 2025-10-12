class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0 , r =0, maxLen = 0;
        vector<int> Hash(256, -1);

        while(r < s.size()){
            if(Hash[s[r]] != -1){
                if(Hash[s[r]] >= l){
                    l = Hash[s[r]] + 1;
                }
            }
            int len = r-l+1;
            maxLen = max(maxLen , len);
            Hash[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};