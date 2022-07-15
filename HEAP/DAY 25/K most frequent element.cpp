// TC O(klogd)--> d--no of unique elements   Sc O(k)

#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{              //a[i]-->freq
   unordered_map<int,int>mp;
    for(auto x:arr){
        mp[x]++;
    }             //freq-->a[i]
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    for(auto x:mp){
        pq.push({x.second,x.first});
        if(pq.size()>k)pq.pop();
        
    }
    vector<int>ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
}
