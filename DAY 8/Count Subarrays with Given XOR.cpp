#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
     /*
     M1 TC O(n) SC O(1)
     int cnt=0;
    for(int i=0;i<arr.size();i++){
        int cur_xr=0;
        for(int j=i;j<arr.size();j++){
             cur_xr^=arr[j];
            if(cur_xr==x)cnt++;
        }
    }
    return cnt; */
    
    // TC O(n) SC O(n)
    unordered_map<int,int>mark;
    int cur_xr= 0;
    long long cnt=0;
    for(int i=0;i<arr.size();i++){
        cur_xr^=arr[i];
        if(cur_xr==x) cnt++;
        int h = cur_xr^x;
        if(mark.find(h)!=mark.end()){
            cnt=cnt+mark[h];
        }
        mark[cur_xr]++;
    }
    return cnt;
    
}
