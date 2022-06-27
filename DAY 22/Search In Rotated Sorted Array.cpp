// TC O(logn)
int search(int* arr, int n, int key) {
  int low=0,high=n-1;

   while(low<=high){

       int mid=low+(high-low)/2;

       if(arr[mid]==key)

           return mid;

       if(arr[low]<=arr[mid]){

           if(arr[low]<=key and key<arr[mid]){

               high=mid-1;

           }

           else{

               low=mid+1;

           }

       }

       else{

           if(arr[mid]<key and arr[high]>=key){

               low=mid+1;

           }

           else{

               high=mid-1;

           }

       }

   }

   if(arr[low]==key) return low;
    else

       return -1;

}   
    
