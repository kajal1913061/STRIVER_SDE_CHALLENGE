#include<bits/stdc++.h>
void solve(vector<int>ip,int idx,vector<int>ds,int k,vector<vector<int>>&ans){
    if(k==0){
        ans.push_back(ds);
        return;
    }
    for(int i=idx;i<ip.size();i++){
        if(i>idx && ip[i]==ip[i-1])continue;
        if(ip[i]>k)break;
        ds.push_back(ip[i]);
        solve(ip,i+1,ds,k-ip[i],ans);
        ds.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	vector<vector<int>>ans;
    vector<int>ds;
    sort(arr.begin(),arr.end());
    solve(arr,0,ds,target,ans);
    return ans;
}
