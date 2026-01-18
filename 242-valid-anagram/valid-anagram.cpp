class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq_S[26] = {0};
			int freq_t[26] = {0};
            // to be of same length
			if(s.length() != t.length())  return false;

			for(int i = 0 ; i < s.length() ; i++){
                //counting the frequency of s and t
				freq_S[s[i] - 'a']++;
				freq_t[t[i] - 'a']++;
			}
			for(int i = 0 ; i < 26 ; i++){
                //if the count is not same
				if(freq_S[i] != freq_t[i])   return false;
			}
			return true;
    }
};