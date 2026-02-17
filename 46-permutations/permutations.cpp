class Solution {
public:
    void recPermutation(int ind, vector<int> &nums, vector<vector<int>> & ans){
        //base case
        if(ind  == nums.size()){
            ans.push_back(nums);
            return ;
        }
        for(int i = ind; i < nums.size(); i++){
            //swaping from ind -> n
            swap(nums[ind], nums[i]);
            recPermutation(ind + 1, nums, ans);
            //swapping to get back the original
            swap(nums[ind] , nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        recPermutation(0 , nums, ans);
        return ans;
    }
};