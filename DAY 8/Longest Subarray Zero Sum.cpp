

//TC O(n) SC O(n)
#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > A) {

 int mxlen=0,sum=0;
       unordered_map<int,int>m;
       for(int i=0;i<A.size();i++){
           sum+=A[i];
           if(sum==0)mxlen=i+1;
           else
           if(m.find(sum)!=m.end())mxlen=max(mxlen,i-m[sum]); //we use hashmap here,
               //in this sum it checks whether the sum already exists in the hashmap
           else
           m[sum]=i;
       }
       return mxlen;

}
