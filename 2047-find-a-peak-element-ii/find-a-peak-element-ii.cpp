class Solution {
public:
int maxElement(vector<vector<int>> &arr, int col ){
    int n = arr.size();
    int max_val = INT_MIN;
    int index = -1;

    for( int i = 0 ; i < n ; i++){
        if(arr[i][col] > max_val){
            max_val = arr[i][col];
            index = i;
        }
        } 
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
         int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;

        while( low <= high){
            int mid = (low + high)/2;
            int row = maxElement( mat, mid);

            int left = mid - 1 >= 0 ? mat[row][mid - 1]: INT_MIN;
            int right = mid + 1 < m ? mat[row][mid + 1]: INT_MIN;

            if( mat[row][mid] > left && mat[row][mid] > right){
                return {row, mid};
            }
            else if( left > mat[row][mid] ){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return {-1, -1};
    }
};