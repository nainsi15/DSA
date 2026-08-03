class Solution {
public:
    long long gcd(long long nums1, long long nums2){
        while(nums2 != 0){
            long long temp = nums2;
            nums2 = nums1%nums2;
            nums1 = temp;
        }
        return nums1;
    }
    
    long long maxPairStrength(vector<int>& nums) {
        long long result = 0;
        
        for(int i = 0 ; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                
                long long x = gcd(nums[i], nums[j]);
                long  long a = nums[i]/ x;
                long long b = nums[j] / x;
                result = max(result,a*b);
            }
        }
        return result;
    }
};