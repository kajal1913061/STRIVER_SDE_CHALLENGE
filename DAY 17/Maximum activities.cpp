#include<bits/stdc++.h>
const bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    return v1[1] < v2[1];
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    vector<vector<int>>m;
    int n=start.size(),ans=1;
    for(int i=0;i<n;i++){
        m.push_back({start[i],finish[i]});
    }
    sort(m.begin(),m.end(),cmp);
    int last=m[0][1];
    for(int i=1;i<m.size();i++){
        if(last<=m[i][0]){
            ans++;
            last=m[i][1];
        }
    }
    
    return ans;
    
}
