int maximumProfit(vector<int> &prices){
 /*  
 TC O(n^2) SC O(1)
 
 int mx=0,n=prices.size();
    for(int i=0;i<n;i++){
     for(int j=i+1;j<n;j++){
         mx=max(mx,prices[j]-prices[i]);
     }
    }
    return mx; */
  // TC O(N) SC O(1)
    int mn=INT_MAX,mx=0;
    for(int i=0;i<prices.size();i++){
        mn=min(mn,prices[i]);
        mx=max(mx,prices[i]-mn);
    }
    return mx;
}
