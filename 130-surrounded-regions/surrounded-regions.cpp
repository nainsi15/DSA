class Solution {
void dfs(int row, int col , vector<vector<int>> &vis, vector<vector<char>> &mat , int n , int m ){
        vis[row][col] = 1;
        int delrow[] = {-1, 0 , 1 , 0};
        int delcol[] = {0, 1, 0 , -1};

        //check for top, right, bottom , left
        for(int i = 0; i < 4 ; i++){
            int n_row = row +  delrow[i];
            int n_col = col + delcol[i];
            if(n_row >= 0 && n_row < n  && n_col >=0 && n_col < m){
                if(!vis[n_row][n_col] && mat[n_row][n_col] == 'O'){
                    dfs(n_row, n_col, vis, mat, n , m );
                }
            }

        }
    }
public:
    void solve(vector<vector<char>>& board) {
        //determine the dimensions of the matrix
        int n = board.size();
        int m = board[0].size();
       //visited array
       vector<vector<int>> vis(n, vector<int>(m,0));

       //traverse boundary row
       for(int j = 0 ; j < m ;j++){
            //traverse first row
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j , vis, board, n, m);
            }
            //traverse last row
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1, j , vis, board, n, m);
            }
       }

       //traverse the boundary col
       for(int i = 0 ; i < n ; i++) {
        //traverse first col
        if(!vis[i][0] && board[i][0] == 'O'){
            dfs( i, 0 ,vis, board, n, m );
        }
        //traverse last col
        if(!vis[i][m-1] && board[i][m-1] == 'O'){
            dfs(i, m-1 ,vis, board, n, m );
        }
       }
       //traverse the rest matrix
       for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j  <m ; j++){
            if(!vis[i][j] && board[i][j] == 'O'){
                board[i][j] = 'X';
            }
        }
       }
       return;
    }
};