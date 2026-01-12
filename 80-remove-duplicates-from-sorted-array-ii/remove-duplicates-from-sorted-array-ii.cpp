class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //starting index for i
        int i = 2;
        if(i >= nums.size()){
            return nums.size();
        }
       for(int j = 2; j < nums.size(); j++){
        if(nums[j] != nums[i-2]){
            nums[i] = nums[j];
            i++;
        }
       }
       return i;
    }
};