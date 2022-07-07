/*
N = 5, K = 2
Arr[] = {12, 5, 787, 1, 23}
Output: 787 23


*/

vector<int> kLargest(int arr[], int n, int k) {
// 	  sort(arr,arr+n);
// 	  vector<int>ans;
// 	  for(int i=n-1;i>=(n-k);i--){
// 	      ans.push_back(arr[i]);
// 	  }
	  
// 	  return ans;
// 	}

	    vector<int>ans;
	    priority_queue<int,vector<int>,greater<int>>pq;
	    for(int i=0;i<n;i++){
	        pq.push(arr[i]);
	        if(pq.size()>k){
	            pq.pop();
	        }
	    }
	    while(!pq.empty()){
	        ans.push_back(pq.top());
	        pq.pop();
	    }
	    
	   reverse(ans.begin(),ans.end());
	   return ans;
	    
	}
