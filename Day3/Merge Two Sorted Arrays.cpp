//TC O(n+m) SC O(1)

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	//vector<int>ans;
    int i=m-1,j=n-1,k=m+n-1;
    while(j>=0){
       arr1[k--]=i>=0&& arr1[i]>arr2[j]?arr1[i--]:arr2[j--];
    }
    return arr1;
}
