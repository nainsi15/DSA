class Solution {
public:
int findMax(vector<int> &nums){
    int n = nums.size();
    int maxi = INT_MIN;

    for(int i =0; i < n ; i++){
        maxi = max(maxi, nums[i]);
    }
    return maxi;
}
long long calculateTotalHours(vector<int> &nums, int hourly){
    int n = nums.size();
    long long totalH = 0;
    for(int i = 0; i < n ;i++){
        totalH += ceil((double) nums[i]/ (double) hourly);
    }
    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1 ;
    int high = findMax(piles);
    while(low <= high){
        int mid = (low + high)/2;
        long long requiretime = calculateTotalHours(piles, mid);
        if( requiretime <= h){
        high = mid -1;
        }
        else{
            low = mid +1;
        }
    }
        return low;
    }
};