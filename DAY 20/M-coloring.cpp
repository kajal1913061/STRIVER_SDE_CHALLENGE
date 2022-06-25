
// Tc O( N^M)  SC O(n)
bool isSafe(int node,vector<vector<int>>&mat,vector<int>&color,int n,int col){
    for(int i=0;i<n;i++){
        if(i!=node && mat[i][node]==1 && color[i]==col)return false;
    }
    return true;
}

bool solve(int node,vector<vector<int>>&mat,vector<int>&color,int m,int n){
    if(node==n)return true;
    for(int i=1;i<=m;i++){
        if(isSafe(node,mat,color,n,i)){
            color[node]=i;
            if(solve(node+1,mat,color,m,n))return true;
            color[node]=0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
   int n=mat.size();
    vector<int>color(n,0);
    if(solve(0,mat,color,m,n))return "YES";
    else
        return "NO";
    
}
