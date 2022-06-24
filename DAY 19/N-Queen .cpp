/*  
// This sol  gives TLE --> TC O(n!*n ) SC o(n^2)

bool isSafe(int row,int col,vector<vector<int>>board,int n){
    int r=row,c=col;
    while(col>=0 && row>=0){
        if(board[row][col]==1)return false;
    row--;
    col--;
    }
    row=r;
    col=c;
    while(col>=0){
        if(board[row][col]==1)return false;
    col--;      
  }
    col=c;
    while(row<n && col>=0){
        if(board[row][col]==1)return false;
     row++;
        col--;
    }
    
}
void solve(int col,vector<vector<int>>board,vector<vector<int>>&ans,int n){
  if(col==n){
      vector<int>temp;
      for(auto i:board){
          for(auto j:i)
              temp.push_back(j);
      }
      ans.push_back(temp);
      }
    for(int r=0;r<n;r++){
        if(isSafe(r,col,board,n)){
            board[r][col]=1;
            solve(col+1,board,ans,n);
            board[r][col]=0;
            
        }
    }
      
}
vector<vector<int>> solveNQueens(int n) {
  vector<vector<int>>ans;
   vector<vector<int>>board(n,vector<int>(n,0));
    solve(0,board,ans,n);
    return ans;
    
}*/

// TC O(N! * N) SC O(n)

vector<vector<int>> ans;
void solve(int col, vector<vector<int>> &board, vector<int> &leftRow, vector<int> &upperDiagonal, vector<int> lowerDiagonal, int n)

{

   if(col == n)

   {

       vector<int> temp;

       for(auto it:board)

       {

           for(auto i:it)

               temp.push_back(i);

       }  

       ans.push_back(temp);

       return;

   }
for(int row=0; row<n; row++)

   {

       if(leftRow[row]==0 && upperDiagonal[n-1 + col - row]==0 && lowerDiagonal[row+col]==0)

       {

          board[row][col] = 1;

           leftRow[row] = 1;

           lowerDiagonal[row+col] = 1;

           upperDiagonal[n-1 + col - row] = 1;

           solve(col+1,board, leftRow, upperDiagonal, lowerDiagonal, n);

           board[row][col] = 0;

           leftRow[row] = 0;

           lowerDiagonal[row+col] = 0;

           upperDiagonal[n-1 + col - row] = 0;
 }

   }}
vector<vector<int>> solveNQueens(int n) {

   vector<vector<int>>board(n, vector<int>(n, 0));

   vector<int> leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1,0);
    solve(0, board, leftRow, upperDiagonal, lowerDiagonal, n);
   return ans;
}
