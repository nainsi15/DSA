class Solution {
public:
bool IsPossible( vector<string> &board, int row, int col){
    int r = row , c = col;
    // for top condition
    while( r >= 0){
        if(board[r][c] == 'Q')
        return false;
        r--;
    }
    r =row; 
    c= col;
    // for left diagnol
     while( r >= 0 && c >= 0){
        if(board[r][c] == 'Q')
        return false;
        r--;
        c--;
    }
     r =row; 
    c= col;
     while( r >= 0 && c < board.size()){
        if(board[r][c] == 'Q')
        return false;
        r--;
        c++;
    }
    return true;
}

void func( int row, vector<string> &board, vector<vector<string>> &ans){
    if( row == board.size()){
        ans.push_back(board);
        return;
    }
    for(int col =0 ; col < board.size(); col++){
        if(IsPossible(board, row, col)){
            board[row][col] = 'Q';
            func(row +1, board, ans);
            board[row][col] = '.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n , string(n ,'.'));
        func( 0 , board, ans);
        return ans;
    }
};