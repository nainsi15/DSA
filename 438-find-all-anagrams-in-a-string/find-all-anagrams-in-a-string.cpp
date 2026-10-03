class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int hash[256] = {0};
        
        for(int i = 0 ; i < p.size() ; i++){
            hash[p[i]]++;
        }

        int l = 0, r = 0,count =0;

        while(r < s.size()){
            if(hash[s[r]] > 0 ){
                count++;
            }
            hash[s[r]]--;

            while(count == p.size()){
                if(r-l+1 == p.size()){
                ans.push_back(l);
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    count--;
                }
                l++;
            }
            r++;
        }
        return ans;
    }
};