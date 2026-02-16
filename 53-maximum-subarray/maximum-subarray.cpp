class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long maxsum = LLONG_MIN;
        long long current = 0;

        for( int i = 0 ; i  < n ; i++){
            //add current element to the sum
            current += nums[i];
            if(current > maxsum){
                maxsum = current;
            }
            //if sum becomes -ve then reset
            if(current < 0){
            current = 0;
        }
        }
        return maxsum;
    }
};