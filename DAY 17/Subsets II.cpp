/*Test Case Input
4
3
1 1 3
4
1 3 3 3
4
5 5 3 5 
3
1 3 5 
Desired Output

1 
1 1 
1 1 3 
1 3 
3 

1 
1 3 
1 3 3 
1 3 3 3 
3 
3 3 
3 3 3 

3 
3 5 
3 5 5 
3 5 5 5 
5 
5 5 
5 5 5 

1 
1 3 
1 3 5 
1 5 
3 
3 5 
5
 */

#include<bits/stdc++.h>
void solve(vector<int>ip,vector<int>op,set<vector<int>>&ans){
    if(ip.size()==0){
        sort(op.begin(),op.end());
        ans.insert(op);
        return;
    }
    vector<int>op1=op,op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1,ans);
    solve(ip,op2,ans);
    return;
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>>res;
    vector<int>op;
    
    set<vector<int>>ans;
    solve(arr,op,ans);
    for(auto x:ans){
      
        res.push_back(x);
    }
    return res;
      
}
