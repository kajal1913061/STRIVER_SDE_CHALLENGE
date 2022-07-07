// M1 using sorting O(nlogn) SC O(1)
sort(arr,arr+r+1);
    return arr[k-1];

// M2 using heap  TC O(nlogk) SC O(k)
priority_queue<int>pq;  //maxheap
      for(int i=0;i<n;i++){
          pq.push(arr[i]);
          if(pq.size()>k){
              pq.pop();
          }
      }
      return pq.top();
    }

