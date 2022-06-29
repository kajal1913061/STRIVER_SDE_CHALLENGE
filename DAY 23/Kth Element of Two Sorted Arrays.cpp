int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int n, int m, int k) {
  // M1 TC o(n+m) Sc O(n+m)
    vector<int>v(n+m,0);
    int i=0,j=0,k=0;
    
    while(i<n&&j<m){
        if(row1[i]<row2[j])v[k++]=row1[i++];
        else
            v[k++]=row2[j++];
    }
    if(i<n){while(i<n){v[k++]=row1[i++];}}
    if(j<m){while(j<m){v[k++]=row2[j++];}}
//     if(i<n)v[k++]=row1[i++];
//     else
//         if(j<m)v[k++]=row2[j++];
 
    return v[K-1];  
}

  // M1 TC O(k) SC O(1)
  int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) { 
         int i=0,j=0;
         int ans=0,cnt=0;    
    while(i<m && j<n){
        if(row1[i]<row2[j]){
            cnt++;
            if(cnt==k){
                ans= row1[i];}
            i++;
        }
        else{cnt++;
             if(cnt==k){
                 ans= row2[j];
             }
             j++;
            }
    }
    while(i<m){
        cnt++;
        if(cnt==k){
            ans= row1[i];
        } 
        i++;
    }    
    while(j<n){
        cnt++;
        if(cnt==k){
            ans= row2[j];
        }
        j++;
    }    
return ans; } 
  
  // M3 Tc O(log(min(n,m)) SC O(1)
#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k){
    int l=max(0,k-n),h=min(k,m);
    while(l<=h){
        int cut1=(l+h)/2,cut2=k-cut1;
        int l1=(cut1==0)?INT_MIN:row1[cut1-1];
        int l2=(cut2==0)?INT_MIN:row2[cut2-1];
        int r1=(cut1==m)?INT_MAX:row1[cut1];
        int r2=(cut2==n)?INT_MAX:row2[cut2];
        if(l1<=r2 && l2<=r1)return max(l1,l2);
        else
            if(l1>r2)h=cut1-1;
        else
            l=cut1+1;
        
    }
    return 1;
}
