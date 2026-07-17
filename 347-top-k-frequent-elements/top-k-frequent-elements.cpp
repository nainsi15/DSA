class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }

        vector<vector<int>> bucket(nums.size() +1);

        for(auto &it : mp){
            int element = it.first;
            int freq = it.second;
            bucket[freq].push_back(element);
        }
        
        vector<int> res;
        for(int  i = bucket.size()-1; i >= 0; i--){
            if(bucket[i].size() == 0) continue;
            while(!bucket[i].empty() && k > 0){
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return res;
    }
};