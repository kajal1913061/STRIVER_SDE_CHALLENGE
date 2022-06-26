#include<bits/stdc++.h>
// TC O(nlogn) Sc O(n)
int getMedian(vector<vector<int>> &matrix)
{
   vector<int>temp;
    for(auto x:matrix){
        for(auto y:x){
            temp.push_back(y);
        }
    }
    sort(temp.begin(),temp.end());
    int n=(temp.size())/2;
    return temp[n];
}

//Using binary search
int noOfElementLessThanOrEqualtoMid(vector<int> &arr,int mid){
    int s=0,e=arr.size()-1;
    
    while(s<=e){
        int m=s+(e-s)/2;
        if(arr[m]<=mid){
            s=m+1;
        }else{
            e=m-1;
        }
    }
    return s;
}

int getMedian(vector<vector<int>> &matrix)
{
    int n=matrix.size();
    int m=matrix[0].size();
   int low=0,high=1e6;
    
    while(low<=high){
        int mid=low+(high-low)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=noOfElementLessThanOrEqualtoMid(matrix[i],mid);
        }
        
        if(cnt<=(n*m)/2) low=mid+1;
        else high=mid-1;
        
    }
    return low;
    
   
}
