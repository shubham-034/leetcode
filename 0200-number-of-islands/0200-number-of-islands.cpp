class Solution {
public:
    void DFS(int i,int j,vector<vector<bool>>&vis,vector<vector<char>>&grid,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1' || vis[i][j]){
            return;
        }
        vis[i][j]=true;
        //neighbours:
        DFS(i-1,j,vis,grid,n,m);//Top
        DFS(i+1,j,vis,grid,n,m);//Bottom
        DFS(i,j-1,vis,grid,n,m);//Left
        DFS(i,j+1,vis,grid,n,m);//Right
    }

    int numIslands(vector<vector<char>>& grid) {
        int island=0;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    DFS(i,j,vis,grid,n,m);
                    island++;
                }
            }
        }
        return island;
    }
};