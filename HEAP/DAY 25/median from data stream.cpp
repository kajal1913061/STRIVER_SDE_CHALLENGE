// M1 using insertion sort ---> TC O(n^2)

// M2 using heap --> TC O(nlogn)
#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
   priority_queue<int>max;
   priority_queue<int,vector<int>,greater<int>>min;
    if(n==0)return;
    max.push(arr[0]);
    cout<<arr[0]<<" ";
   for(int i=1;i<n;i++){ 
    if(max.size()>min.size()){
        if(max.top()>arr[i])
        {
            min.push(max.top());
            max.pop();
            max.push(arr[i]);
        }
        else
            min.push(arr[i]);
        cout<<(((int)max.top()+min.top())/2)<<" ";
        }
       else{
           if(max.top()>=arr[i])max.push(arr[i]);
           else{
               min.push(arr[i]);
               max.push(min.top());
               min.pop();
           }
           cout<<max.top()<<" ";
       }
       
           
    }
          
        
}
