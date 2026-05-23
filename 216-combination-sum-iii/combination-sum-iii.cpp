class Solution {
private:
    void func(int ind, int k, int n , vector<vector<int>>& ans, vector<int>& arr, int sum){
        if(sum > n || arr.size() > k ) return;
        if(arr.size() == k){
            if(sum == n ){
            ans.push_back(arr);
        }
        return;
        }
        for(int i = ind + 1 ; i<= 9 ;i++){
            arr.push_back(i);
            sum += i;
            func(i, k, n , ans, arr, sum);
            sum -= i;
            arr.pop_back();
        }


    }
public:
    vector<vector<int> > combinationSum3(int k, int n) {
    	vector<vector<int>> ans;
        vector<int> arr;
        func(0, k, n , ans, arr, 0);
        return ans;
    }
};