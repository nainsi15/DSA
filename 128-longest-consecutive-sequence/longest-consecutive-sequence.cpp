class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0 ;
        unordered_set<int> mp;
       
        for(int i = 0 ; i < n; i++){
            mp.insert(nums[i]);
        }
        int maxcount = 1;
        for(auto it : mp){
            if(mp.find(it-1) == mp.end()){
                int count = 1;
                int current = it;
                while(mp.find(current + 1) != mp.end()){
                    current++;
                    count++;
                }
                maxcount = max(maxcount, count);
            }
            }
        return maxcount;
    }
};