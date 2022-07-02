// TC O(nlogn) SC O(1)
class Solution 
{
    public:
    bool Ispos(int A[],int N,int barrier,int M){
        int std=1,page=0;
        for(int i=0;i<N;i++){
           
            if(page+A[i]<=barrier){
                page+=A[i];
            }else{
                if(A[i]>barrier)return false;
                
                std++;
                page=A[i];
            }
            
        }
        
        return (std<=M)?true:false;
    }
    int findPages(int A[], int N, int M) 
    {
        int h=accumulate(A,A+N,0),res=0;
       int s=A[0];
       while(s<=h){
           int m=(s+h)/2;
           if(Ispos(A,N,m,M)){
              // res=m;
               h=m-1;
           }
           else{
               s=m+1;
           }
       }
       return s;
    }
};
