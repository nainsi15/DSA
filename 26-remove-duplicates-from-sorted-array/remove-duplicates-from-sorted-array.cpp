class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0 ;
        for(int j = 1; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
            // because i stated from 0 and it's the index , therefore + 1
            return i+1;
        }
};