class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //if emty string 
			if(strs.empty()) return "";

			int n = strs.size();
			// Sort the vector to get the lexicographically smallest and largest strings
			sort(strs.begin(), strs.end());

			//first string
			string first = strs[0];
			//last string
			string last = strs[n-1];
			string ans = "";
			// Compare characters of the first and last strings
			int minlength = min(first.size(), last.size());
			for(int i = 0 ; i < minlength ; i++){
				if(first[i] != last[i]){
				return ans;
				}
				ans += first[i];
			}
				return ans;
    }
};