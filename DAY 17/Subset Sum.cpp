// Using recursion
#include<bits/stdc++.h>
void solve(vector<int>ip,vector<int>op,vector<int>&ans){
    if(ip.size()==0){
        int n=op.size(),sum=0;
        for(int i=0;i<n;i++)sum+=op[i];
        ans.push_back(sum);
        return;
    }
    vector<int>op1=op,op2=op;
   
    op2.push_back(ip[0]);
   ip.erase(ip.begin()+0);
    solve(ip,op1,ans);
    solve(ip,op2,ans);
    
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int>ans,op;
   // vector<int>ip=num;
    solve(num,op,ans);
    sort(ans.begin(),ans.end());
    return ans;
    
}
