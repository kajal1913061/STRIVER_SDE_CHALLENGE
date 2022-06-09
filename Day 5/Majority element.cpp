#include <bits/stdc++.h> 

// TC O(n) SC O(n)
int findMajorityElement(int arr[], int n) {
	unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    n=n/2;
    for(auto &x:m){
        if(x.second>n)return x.first;
    }
    return -1;
}
