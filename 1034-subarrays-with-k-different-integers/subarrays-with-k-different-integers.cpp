class Solution {
private:
 int atMost(vector<int>& nums, int k){
    int l = 0 , r = 0 ;
       int n = nums.size();
       unordered_map<int, int> mp;
       int count  =0;

       while(r < n){
        if(mp[nums[r]] == 0){
            k--;
        }
        mp[nums[r]]++;
        
        while(k < 0){
            mp[nums[l]]--;
            if(mp[nums[l]] == 0){
                k++;
            }
            l++;
        }
        count += r-l+1;
        r++;
       }
    return count;
 }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};