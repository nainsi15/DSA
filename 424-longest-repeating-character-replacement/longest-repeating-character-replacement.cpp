class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        int maxFreq = 0;
        int l = 0, r =0;

        int hash[26] = {0};

        while(r < s.size()){
        hash[s[r] - 'A']++;
        maxFreq = max(maxFreq , hash[s[r] - 'A']);
        int conversions = (r-l+1) - maxFreq;

        if(conversions > k){
          hash[s[l] -'A']--;
          maxFreq = 0;
          
          l++;
        }
        if(conversions <= k){
          maxlen = max(maxlen , r-l+1);
        }
        r++;
        }
        return maxlen;
    }
};