#include<bits/stdc++.h>
double median(vector<int> a, vector<int> b)
{  
  // O(nlogn)
 /* double ans=0.0;
    for(auto x:b){
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int n=a.size();
    if(n%2==0){
        int x=(n/2)-1,y=0;
        y=x+1;
        ans=(a[x]+a[y])/2.0;
    }else{
        int x=n/2;
        ans=a[x];
    }
    return ans;  */
    
  /* 
  TC O(n+m) SC O(n+m)
  int n=a.size(),m=b.size();
    vector<int>temp(n+m,0);
    int i=0,j=0,k=0;
    
    while(i<n&&j<m){
        if(a[i]<b[j])temp[k++]=a[i++];
        else
            temp[k++]=b[j++];
    }
    if(i<n)temp[k++]=a[i++];
    if(j<m)temp[k++]=b[j++];
    if((n+m)%2==1)return double(temp[(n+m)/2]);
    return double((temp[(n+m)/2-1]+temp[(n+m)/2])/2.0);
    */
    
    // optimized TC O(logn) Sc O(1)
    if(a.size()>b.size())return median(b,a);
    int m=a.size(),n=b.size();
    int low=0,high=m;
    while(low<=high){
        int cut1=(low+high)/2;
        int cut2=(n+m+1)/2-cut1;
        int l1=(cut1==0)?INT_MIN:a[cut1-1];
        int l2=(cut2==0)?INT_MIN:b[cut2-1];
        int r1=(cut1==m)?INT_MAX:a[cut1];
        int r2=(cut2==n)?INT_MAX:b[cut2];
        
        if(l1<=r2 && l2<=r1){
            if((n+m)%2==0){
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else
                return max(l1,l2);
        }
        else
        if(l1>r2)high=cut1-1;
        else
            low=cut1+1;
    }
    return 0.0;
}
