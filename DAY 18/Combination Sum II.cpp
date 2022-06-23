
// Give TLE using recursion--->> TC O(2^n*k*logn)
#include<bits/stdc++.h>
void solve(vector<int>ip,vector<int>op,int k,set<vector<int>>&temp){
    if(ip.size()==0){
        int sum=0;
        for(auto x:op)sum+=x;
        if(sum==k){
            sort(op.begin(),op.end());
            temp.insert(op);
        }
        return;
    }
    vector<int>op1=op,op2=op;
    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);
    solve(ip,op1,k,temp);
    solve(ip,op2,k,temp);
    return;
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int k)
{
    vector<vector<int>>ans;
    vector<int>op;
    set<vector<int>>temp;
    solve(arr,op,k,temp);
	for(auto x:temp)ans.push_back(x);
    return ans;
}





//TC:O(2^n*k)  SC:O(k*x)

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
