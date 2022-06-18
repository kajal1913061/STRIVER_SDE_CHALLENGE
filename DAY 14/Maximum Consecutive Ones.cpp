int longestSubSeg(vector<int> &arr , int n, int k){
   /* int j=-1;
    int zeroCount=0;
    int ans=0;
    
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zeroCount++;
        }
        while(zeroCount>k){
            j++;
            if(arr[j]==0){
                zeroCount--;
            }
        }
        int len=i-j;
        if(len>ans){
            ans=len;
        }
    }
    return ans;
    */
  
   int i=0;
   int j=0;
   int ans=0;
   int kdup=k;
   while(j<n && i<n){
       if(arr[j]==1){
           ans=max(j-i+1,ans);
           j++;
       }
       else if(arr[j]==0){
           if(k){
               k--;
               ans=max(j-i+1,ans);
               j++;
           }
           else{
               if(arr[i]==0){
                   if(k<kdup)
                       k++;
               }
               i++;
           }
       }
   }
   return ans;
}
