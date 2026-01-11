class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
    //mark the node visited
    vis[row][col] = 1;
    //q required for bfs
    queue<pair<int, int>> q;
    q.push({row,col});
    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        //determining rows and colums
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        //traverse the neighbours
         int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++){
            int neighrow = row + drow[i];
            int neighcol = col + dcol[i];
                /* Check if the new cell is valid, 
                    unvisited, and a land cell */
                    if(neighrow >= 0 && neighrow < n && neighcol >= 0 && neighcol < m && grid[neighrow][neighcol] == '1' && !vis[neighrow][neighcol]){
                        vis[neighrow][neighcol] = 1;
                        q.push({neighrow, neighcol});

                    }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        //size of the gridint n = grid.size();
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        //visted array
        //n rows with m colums marked all as 0
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int row = 0 ; row < n ; row++){
            for(int col =0 ; col < m ; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return count;
    }
};