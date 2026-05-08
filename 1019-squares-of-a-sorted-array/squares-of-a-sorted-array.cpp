class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int x = nums.size();
        vector<int> neg;
        vector<int> pos;
        

        for(int i = 0 ; i < x; i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        //only negative elements
            for(int i = 0 ; i < neg.size(); i++){
                neg[i] *= neg[i];
            }
            reverse(neg.begin(), neg.end());

        //only positive elements
            for(int i = 0 ; i < pos.size(); i++){
                pos[i] *= pos[i];
            }
        
        // if neg and pos 
        int i = 0, j =0;
        int n = neg.size();
        int m = pos.size();
        vector<int> res;

        

        while (i < n && j < m){
            if(neg[i] < pos[j]){
                res.push_back(neg[i]);
                i++;
            }
            else{
                res.push_back(pos[j]);
                j++;
            }
        }
        while(i < n){
            res.push_back(neg[i]);
            i++;
        }
        while(j < m){
            res.push_back(pos[j]);
            j++;
        }
    return res;

    }
};