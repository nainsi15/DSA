class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0 , l= 0, r = 0, zero = 0;
      // r shouldot exceed the array
       while(r < nums.size()){
        if(nums[r] == 0) {
        zero++;
        }
        while(zero > k){
          if(nums[l] == 0){ 
          zero--;
        }
        l++;
        }

        if(zero <= k){
          int len = r-l+1;
          maxLen = max(maxLen , len);
        }
        r++;
       } 
       return maxLen;
    }
};