
// TC O(n) SC O(n)
#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
   vector<long>maxL(n,0),maxR(n,0);
    maxL[0]=arr[0];
    for(long i=1;i<n;i++){
        maxL[i]=max(maxL[i-1],arr[i]);
    }
    maxR[n-1]=arr[n-1];
    for(long i=n-2;i>=0;i--){
        maxR[i]=max(maxR[i+1],arr[i]);
    }
long i=0,sum=0;
    for( i=0;i<n;i++){
        sum+=(min(maxL[i],maxR[i])-arr[i]);
    }
    return sum;
}

    
