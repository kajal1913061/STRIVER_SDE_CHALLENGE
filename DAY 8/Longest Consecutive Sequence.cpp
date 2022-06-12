/* M1 using sorting
simply sort the array and run a for loop to find the longest consecutive sequence.
TC O(nlogn) SC o(1)
*/


// M2 using hash map---->TC O(n) SC o(n)
int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
     unordered_set<int>s;
        int mxlen=0;
        for(auto x:nums)s.insert(x);
      
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)!=s.end())continue;
            else
            {
                int cnt=0,cur=nums[i];
                while(s.find(cur)!=s.end()){
                    cnt++;
                    cur++;
                }
               mxlen=max(mxlen,cnt); 
            }
        }
        return mxlen;
}
