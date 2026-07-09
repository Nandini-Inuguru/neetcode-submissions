class Solution {
public:
    int row;
    int col;
    void dfs(int r,int c,vector<vector<int>>& heights,vector<vector<bool>>& visit){
        if(visit[r][c]){
            return;
        }
        visit[r][c]=true;
        vector<pair<int,int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto& d:dir){
            int nr=r+d.first;
            int nc=c+d.second;
            if(nr<0 || nc<0 || nr>=row || nc>=col){
                continue;
            }
            if(visit[nr][nc]){
                continue;
            }
            if(heights[nr][nc]<heights[r][c]){
                continue;
            }
            dfs(nr,nc,heights,visit);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row=heights.size();
        col=heights[0].size();
        vector<vector<bool>> pacific(row,vector<bool>(col,false));
        vector<vector<bool>> atlantic(row,vector<bool>(col,false));
        for(int c=0;c<col;c++){
            dfs(0,c,heights,pacific);
        }
        for(int r=0;r<row;r++){
            dfs(r,0,heights,pacific);
        }
        for(int c=0;c<col;c++){
            dfs(row-1,c,heights,atlantic);
        }
        for(int r=0;r<row;r++){
            dfs(r,col-1,heights,atlantic);
        }
        vector<vector<int>> ans;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
