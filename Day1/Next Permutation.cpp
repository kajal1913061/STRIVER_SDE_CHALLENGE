// Brute force
generate all possible permutation and then search the given number whose next permuation is find.-->> TC O(n!) SC O(n)

// using stl fun
next_permutation(a.begin(), a.end())--->> TC O(n!) when every element is distinct and in best case TC O(n)


// Optimized TC O(n) SC o(1)
#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &nums, int N)
{       int  i, j;
        for (i =nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i< 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for (j=nums.size() - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    break;
                }
            } 
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());}
            return nums;
}
