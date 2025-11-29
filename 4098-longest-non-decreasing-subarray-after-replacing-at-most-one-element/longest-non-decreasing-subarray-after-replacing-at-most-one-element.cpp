class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> res = nums;
        if(nums.size()==1) return 1;

        vector<int> prefix(nums.size() , 1), suffix(nums.size(), 1);

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] >= nums[i-1])
                prefix[i] = prefix[i - 1] +1;
        }
        for(int j = nums.size() - 2; j >=0; j--){
            if(nums[j] <= nums[j+1])
                suffix[j] =suffix[j+1]+1;
        }
            int answer = *max_element(prefix.begin(), prefix.end());

        for(int k =0 ; k < nums.size(); k++){
            if(k == 0){
                answer = max(answer, 1+(nums.size() > 1 ? suffix[1] : 0));
            }
            else if( k == nums.size() -1){
                answer = max(answer,1+(nums.size() > 1 ? prefix[nums.size()-2] : 0) );
            }
            else{
                if(nums[k - 1] <= nums[k+1]){
                    answer = max(answer, prefix[k-1]+1+suffix[k+1]);
                }
                else{
                    answer = max(answer, prefix[k-1]+1);
                    answer = max(answer, suffix[k+1]+1);
                }
            }
        }
        return min(answer, (int)nums.size());
    }
};