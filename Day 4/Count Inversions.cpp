// M1 TC O(n^2) SC O(1)

/*
Traverse through the array, and for every index, find the number of smaller elements on its right side of the array. 
This can be done using a nested loop. 
Sum up the counts for all index in the array and print the sum.
*/

// M2 TC O(nlogn) SC O(n)--->https://www.geeksforgeeks.org/count-inversions-in-an-array-set-2-using-self-balancing-bst/
/*The idea is to use Self-Balancing Binary Search Tree like Red-Black Tree, AVL Tree, etc and 
augment it so that every node also keeps track of number of nodes in the right subtree. 
So every node will contain the count of nodes in its right subtree i.e. the number of nodes greater than that number.
So it can be seen that the count increases when there is a pair (a,b), where a appears before b in the array and a > b, 
So as the array is traversed from start to the end, add the elements to the AVL tree and 
the count of the nodes in its right subtree of the newly inserted node will be the count increased or the number of pairs (a,b)
where b is the present element.*/

// M3 TC O(n) and in worst case TC O(n^2) SC O(n)

//using stl set--->  https://www.geeksforgeeks.org/counting-inversions-using-set-in-c-stl/

// M4  using bst -->   https://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/

// M5 using merge sort TC O(nlogn) SC O(1)

#include <bits/stdc++.h> 
long long merge(long long *nums, int low, int mid, int high)
    {
        int count = 0;
        int j = mid+1;
        for(int i = low; i <= mid; i++)
        {
            while(j <= high && nums[i] > nums[j])
                j++;
            count += (j-(mid+1));
        }
        
    
        // perform merge
        vector<int> temp;
        int left = low, right = mid+1;
        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
                temp.push_back(nums[left++]);
            else
                temp.push_back(nums[right++]);
        }

        while(left <= mid)
            temp.push_back(nums[left++]);

        while(right <= high)
            temp.push_back(nums[right++]);
        
        for(int i = low; i <= high; i++)
            nums[i] = temp[i-low];
        
        return count;
    }
    
  long long mergeSort(long long *nums, int low, int high)
    {
        if(low >= high) return 0;
         long long mid = (low + high)/2;
        long long val = mergeSort(nums, low, mid);
        val += mergeSort(nums, mid+1, high);
        val += merge(nums, low, mid, high);
        return val;
    }
 long long getInversions(long long *nums, int n){
        return mergeSort(nums, 0, n-1);    
}


