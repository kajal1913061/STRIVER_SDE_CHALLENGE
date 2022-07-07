vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{  /* 

M1 O(nlogn)
  sort(arr.begin(),arr.end());

   vector<int> res;

   res.push_back(arr[k-1]);

   res.push_back(arr[n-k]);
   return res;  */
  
  
  // M2 o(nlogk)
	priority_queue<int>pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<int>ans;
    ans.push_back(pq.top());
    priority_queue<int,vector<int>,greater<int>>p;
    for(int i=0;i<n;i++){
        p.push(arr[i]);
        if(p.size()>k){
            p.pop();
        }
    }
    ans.push_back(p.top());
    return ans;
}
