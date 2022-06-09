#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{  
  //TC O(n) SC  O(n)
  vector<int>ans;
 int n=arr.size();
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    n=n/3;
    for(auto &x:m){
        if(x.second>n)ans.push_back( x.first);
    }
    return ans;
  
  
  // M2 using Extended Boyer Moore’s Voting Algorithm--->TC O(n) SC O(1)
  
   int sz = nums.size();
  int num1 = -1, num2 = -1, count1 = 0, count2 = 0, i;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
    else if (count1 == 0) {
      num1 = nums[i];
      count1 = 1;
    } else if (count2 == 0) {
      num2 = nums[i];
      count2 = 1;
    } else {
      count1--;
      count2--;
    }
  }
  vector < int > ans;
  count1 = count2 = 0;
  for (i = 0; i < sz; i++) {
    if (nums[i] == num1)
      count1++;
    else if (nums[i] == num2)
      count2++;
  }
  if (count1 > sz / 3)
    ans.push_back(num1);
  if (count2 > sz / 3)
    ans.push_back(num2);
  return ans;
}


}
