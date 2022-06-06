// Brute force sol TC O(n^2)
take 2 loop-> one loop for traversing each element in arr and 2nd is used to find subarray and find sum of its subarray. Update max sum till the last element of array.


// Optimized sol using Kadane’s Algorithm--> TC O(n) S.C. O(1)
long long maxSubarraySum(int arr[], int n)
{   long long mx=INT_MIN,cumS=0;
    for(int i=0;i<n;i++){
        cumS+=arr[i];
        mx=max(cumS,mx);
        if(cumS<0)cumS=0;
    }
 if(mx<0)return 0;
 else
 return mx;
}
