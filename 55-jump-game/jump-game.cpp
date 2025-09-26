class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MaxInd = 0;

        for(int i = 0 ; i < nums.size(); i ++){
            if(MaxInd < i) return false;
            MaxInd = max ( MaxInd, i + nums[i]);
        }
        return true;
    }
};