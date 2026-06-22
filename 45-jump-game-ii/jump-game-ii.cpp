class Solution {
public:
    int jump(vector<int>& nums) {
         int n = nums.size();
       int farthest = 0, currentend = 0, jump = 0;

       for (int i = 0; i < n-1; i++){
        farthest = max(farthest, i + nums[i]);
        if(i == currentend){
            jump++;
            currentend = farthest;
        }
       }
       return jump;
    }
};