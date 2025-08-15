class Solution {
public:
void func(  int ind, vector<int> &arr, vector<int> &nums, vector<vector<int>> &ans ){
    // base condition
    if (ind == nums.size()){
        ans.push_back(arr);
        return ;
    }
    arr.push_back(nums[ind]);
    func(ind + 1, arr, nums, ans);
    arr.pop_back();

    //to remove duplicates
    for( int  j = ind + 1; j < nums.size(); j++){
        if( nums[j] != nums[ind]){
            func(j, arr, nums, ans);
            return;
        }
    }
    func(nums.size(), arr, nums, ans);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(), nums.end());
        func(0, arr, nums, ans);
        return ans;
    }
};