
// O(4^(m*n)) SC O(n*m)
bool solve(vector<vector<int>>maze,int n,int i,int j,vector<vector<int>>&ans,vector<vector<int>>&res){
    if(i>=n || i<0 || j>=n || j<0 || maze[i][j]==0 || ans[i][j]==1)return false;
    
    if(i==n-1 && j==n-1 && maze[i][j]==1){
        vector<int>path;
        ans[i][j]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                path.push_back(ans[i][j]);
            }
        }
        res.push_back(path);
    }
    ans[i][j]=1;
    solve(maze,n,i+1,j,ans,res); //down
    solve(maze,n,i-1,j,ans,res);//up
    solve(maze,n,i,j+1,ans,res);//right
    solve(maze,n,i,j-1,ans,res);//left
    ans[i][j]=0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  vector<vector<int>>ans(n,vector<int>(n,0));
    vector<vector<int>>res;
    
    solve(maze,n,0,0,ans,res);
    return res;
}
