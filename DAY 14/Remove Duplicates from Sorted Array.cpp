//  TC O(n) SC O(N)
int removeDuplicates(vector<int> &nums, int n) {
set<int> s;
for(int i = 0 ; i < arr.size() ; ++i){
       s.insert(arr[i]);
   }
   return s.size();
}
// TC O(n) SC O(1)
int removeDuplicates(vector<int> &nums, int n) {
	int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[i]!=nums[j])
             {   i++;
            nums[i]=nums[j];
              
             }
       }
        return i+1;
}
