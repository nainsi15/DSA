class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> res;
        vector<int> val;
        for(int i = 0 ; i <nums.size() ;i++){
            if(nums[i] >= 0){
                res.push_back(i);
                val.push_back(nums[i]);
            }
        }
        if(val.size() == 0) 
            return nums;
        k = k % val.size();

        vector<int> rot(val.size());
        for(int j = 0; j < val.size(); j++){
            int new_ind = (j + val.size() - k)% val.size();
            rot[new_ind] = val[j];
        }
        for(int i = 0 ; i <val.size() ; i++){
            nums[res[i]] = rot[i];
        }
        return nums;
    }
};