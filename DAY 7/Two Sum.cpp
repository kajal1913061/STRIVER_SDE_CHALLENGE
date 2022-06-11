
    vector<int> twoSum(vector<int>& nums, int target) {
        // BRUTE FORCE APPROACH O(N2)
//         vector<int>sum;
//        for( int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[i]+nums[j]==target){
//                     sum.push_back(i);
//                     sum.push_back(j);
//                 }}
                
//             }
//         return sum;
        
       // using hashing T.C. O(N) S.C. O(N)
      vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
        
        
        // using two pointer and pair vector T.C. O(NLOGN) S.C O(N)
//     vector<pair<int,int>>mp;
//         for(int i=0;i<nums.size();i++)
//             mp.push_back({nums[i],i});
//             sort(mp.begin(),mp.end());
//             int s=0,e=nums.size()-1;
//            while(s<e) {
//                int sum=mp[s].first+mp[e].first;
//                if(sum>target)
//                 e--;
//             else
//                 if(sum<target)
//                     s++;
//             else
//                 return {mp[s].second,mp[e].second};
               
//              }
        
    
//         return {-1,-1};
        
    }
