class Solution {
vector<int> FindNSE(vector<int> & arr, int & n){
    vector<int> NSE(n, n);
    stack<int> st;

    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if (st.empty()) NSE[i] = n;
        else{
        NSE[i] = st.top();
        }
        st.push(i);
    }
    return NSE;
}
vector<int> FindPSE(vector<int> & arr, int & n){
    vector<int> PSE(n, -1);
    stack<int> st;
    int i = 0;

    for(int i = 0; i <n ; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
       if(st.empty()) PSE[i] = -1;
        else PSE[i] = st.top();
        st.push(i);
    }
    return PSE;
}
public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse = FindNSE(arr, n);
        vector<int> pse = FindPSE(arr, n);
        int mod = 1e9 + 7;
        int sum = 0 ;

        for(int i = 0 ; i < n ; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            long long freq = left * right *1LL;
            int val = (freq* arr[i]*1LL)%mod;
            sum = (sum+val)%mod;
        }
        return sum;
    }
};
