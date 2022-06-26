#include<bits/stdc++.h>

// Tc O(n^2)
int uniqueElement(vector<int> arr, int n)
{
	int lno=0;
   for(auto x:arr){
       int cnt=count(arr.begin(),arr.end(),x);
       if(cnt==1)return x;
   }
    return lno;
}


// TC O(n) SC O(n)
int uniqueElement(vector<int> arr, int n)
{  int lno=0;
	unordered_map<int,int>mp;
    for(auto x:arr){
        mp[x]++;
    }
    for(auto x:mp){
        if(x.second==1){
            lno=x.first;
            break;
        }
    }
    return lno;
}

// TC O(n) SC O(1)
int uniqueElement(vector<int> arr, int n)
{  

            int elem = 0;
            for (int i = 0; i < n; i++) {
                elem = elem ^ arr[i];
            }
            
            return elem;
}

// TC O(logn) SC O(1)
int uniqueElement(vector<int> arr, int n)
{    int low = 0;
            int high = n - 2;
        
            while (low <= high) {
                int mid = (low + high) / 2;
                
                if (mid % 2 == 0) {
                    if (arr[mid] != arr[mid + 1]) 
                    //Checking whether we are in right half

                        high = mid - 1; //Shrinking the right half
                    else
                        low = mid + 1; //Shrinking the left half
                } else {

                    //Checking whether we are in right half
                    if (arr[mid] ==arr[mid + 1]) 
                        high = mid - 1; //Shrinking the right half
                    else
                        low = mid + 1; //Shrinking the left half
                }
            }

            return arr[low];
}
