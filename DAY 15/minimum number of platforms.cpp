
// TC O(nlogn) SC O(1)
#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
   sort(at,at+n);
    sort(dt,dt+n);
    int i=0,j=1,cnt=1;
    while(j<n && i<n){
        if(at[j]<=dt[i])cnt++;
        else
            i++;
       j++;
    }
    return cnt;
}
