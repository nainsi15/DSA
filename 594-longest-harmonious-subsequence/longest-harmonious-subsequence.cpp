class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int maxcount = 0;
        unordered_map<int, int> mp;
        //count frequency of each number
        for(int i = 0 ; i  < n ; i++){
            mp[nums[i]]++;
        }
        for(auto it : mp){
            int x = it.first;
            if(mp.find(x+1) != mp.end()){
                maxcount = max(maxcount, it.second + mp[x+1]);
            }
            }
        return maxcount;
    }
};