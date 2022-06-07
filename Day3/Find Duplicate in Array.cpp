int findDuplicate(vector<int> &nums, int n){
   
  // M1 using 2 loop TC O(n2) SC O(1)
         int dupl=0;
        for(int i=0;i<nums.size();i++){
         for(int j=i+1;j<nums.size();j++){
             if(nums[i]==nums[j]){dupl=nums[i];break;}
         }
     }
        return dupl;
        
        // M2 using sorting TC O(nlogn) SC O(1)
  
       sort(nums.begin(),nums.end());
        int j=1,ans=0;
        for(int i=0;i<nums.size()&& j<nums.size();i++){
            if(nums[i]==nums[j])ans=nums[i];
            else
                j++;
        }
        return ans;  
  
  
        // M3 using hash map tc O(n) sc o(n)
  
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]>1){ans=nums[i];break;}
        }
    return ans;    
    
       // M4 Linked list methodn(floyd warshal alg) TC O(n) SC o(1)
       int slow=0,fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);       // detect cycle
        fast=0;
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }         // meeting point of slow and fast on dupl no
        return slow; 
          
          
        
        // M5 Using binary search
        int s=1,e=nums.size()-1,cnt=0;
        while(s<=e){
            cnt=0;
            int m=s+(e-s)/2;
            for(auto x:nums){
              
                if(m>=x)++cnt;
            }
            if(cnt<=m)s=m+1;
            else
                e=m-1;
            
        }
        return s;
    

}
