vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        set<vector<int>>s;
        for(int i = 0 ; i< nums.size();i++){
            for(int j = i+1 ; j< nums.size();j++){
                int start = j+1;
                int end = nums.size()-1;
                while(start<end){
                    long long  sum = nums[i]+ nums[j]+ 1LL + nums[start]+ nums[end] -1LL;
                    if(sum==target){
                        vector<int>temp={nums[i],nums[j],nums[start],nums[end]};
                        if(s.find(temp)==s.end()){
                            v.push_back(temp);
                            s.insert(temp);
                        }
                        temp.clear();
                        start++;
                        end--;
                    }
                    else if(sum>target){
                        end--;
                    }
                    else{
                        start++;
                    }
                    
                }
            }
        }
        return v ;  
    }
