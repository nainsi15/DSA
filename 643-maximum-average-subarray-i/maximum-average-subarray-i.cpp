class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double average_sum = INT_MIN;
        double sum =0;
        double res =0;
        int l = 0, r = 0;

        while(r < n){
            sum += nums[r];
            int len =r-l+1;
            if(len == k){
                res = sum/k;
                average_sum = max(average_sum, res);
                sum -=nums[l];
                l++;
            }
            r++;
        }
        return average_sum;
    }
};