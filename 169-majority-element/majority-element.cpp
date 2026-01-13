class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
       

        for(int i = 0 ; i < n; i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            int number = it.first;
            int count = it.second;
             if(count > n/2){
            return number;
        }
        }
        return 0;
    }
};