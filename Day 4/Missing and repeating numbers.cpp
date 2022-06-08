pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{   int repeat=0,mis=0;
    for(int i=0;i<n;i++){
        int x=abs(arr[i])-1;
        if(arr[x]<0){
            repeat=x+1;
        }
        else {
            arr[x]=-1*arr[x];
            }
    }
 for(int i=0;i<n;i++){
     if(arr[i]>0){
         mis=i+1;
     }
 }
 return {mis,repeat};
	 
	
}
