 priority_queue<int,vector<int>,greater<int>>p;  // minheap
        for(int i=0;i<nums.size();i++){
            p.push(nums[i]);
            if(p.size()>k){
                p.pop();
            }
        }
        return p.top();
    }
