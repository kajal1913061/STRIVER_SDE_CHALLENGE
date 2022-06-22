#include<bits/stdc++.h>
void solve(vector<int>ip,vector<int>op,int k,vector<vector<int>>&ans){
    if(ip.size()==0){
        int sum=0;
        for(auto x:op){
           sum+=x; 
        }
        if(sum==k)ans.push_back(op);
        return;
    }
    vector<int>op1=op,op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1,k,ans);
    solve(ip,op2,k,ans);
    return;
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
  vector<vector<int>>ans;
    vector<int>op;
    solve(arr,op,k,ans);
    return ans;
}
