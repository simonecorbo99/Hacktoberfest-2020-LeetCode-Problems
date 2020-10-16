class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands=0,i,j,rows=grid.size(),cols=rows?grid[0].size():0;
        for(i=0;i<rows;i++){
            for(j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    eraser(grid,i,j);
                    
                }
            }
        }
        return islands;
    }
    void eraser(vector<vector<char>>&grid,int i,int j){
        int rows=grid.size(),cols=rows?grid[0].size():0;
        if(i<0||j<0||i>=rows||j>=cols||grid[i][j]=='0')return;
        grid[i][j]='0';
        eraser(grid,i-1,j);
        eraser(grid,i,j-1);
        eraser(grid,i+1,j);
        eraser(grid,i,j+1);
    }
};
