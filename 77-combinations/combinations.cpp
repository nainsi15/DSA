class Solution {
private:
    void func(int ind, int n, int k, vector<int> &nums, vector<int> &arr,vector<vector<int>> &ans){
        //for out of bound conditions
        //if got only elements < k 
        //just return 
        //if equal to k then push back
        if(ind == n){
        if(arr.size() == k){
            ans.push_back(arr);
        }
            return;
        }
        //to pick the elements
        arr.push_back(nums[ind]);
        func(ind+1, n, k, nums, arr, ans);
        arr.pop_back();
        //not picking the element
        func(ind+1, n, k, nums, arr, ans);
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        vector<vector<int>> ans;
        vector<int> nums;
        //pushing the required 'n' elemnts to the nums
        for(int i = 1 ; i <= n ; i++){
            nums.push_back(i);
        }
        func(0, n, k, nums, arr, ans);
        return ans;
    }
};