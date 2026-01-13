class Solution {
public:
    void dfs( int node ,vector<vector<int>>& adjls, vector<int>& vis){
        //mark the node visited
        vis[node] = 1;
        for(auto it : adjls[node]){
            if (!vis[it]){
                dfs(it, adjls , vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //variables to store number of nodes
        int V = isConnected.size();
        vector<vector<int>> adjls(V);

        //convert adjacency matrix to adjacency list
       for(int i = 0; i < V ; i++){
        for(int j = 0; j < V ; j++){
            //self nodes not allowed
            if(isConnected[i][j] == 1 && i != j){
                adjls[i].push_back(j);
                adjls[j].push_back(i);
            }
        }
       }
       //visited array
      vector<int> vis(V, 0);
       int count = 0;

       //start the traversal 
       for(int i = 0 ; i < V; i++){
        if(!vis[i]){
            count++;
            dfs(i , adjls, vis);
        }
       }
       return count;

    }
};