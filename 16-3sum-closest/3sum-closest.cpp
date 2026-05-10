class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min_dif = INT_MAX;
        int res_sum = 0;

        for(int i = 0 ; i  < n ; i++){
            int j = i +1;
            int k = n-1;

            while(j < k ){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    return sum;
                }
                int dif = abs(sum - target);
                if(dif < min_dif){
                    min_dif = dif;
                    res_sum = sum;
                }
                else if (sum < target) j++;
                else k--;
                    
                }
            }
        return res_sum;
    }
};