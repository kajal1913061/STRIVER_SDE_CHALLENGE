    void setZeroes(vector<vector<int>>& matrix) {
/*

brute force approach- we will simply traverse through the matrix and we find 0 then will make that particular row and column 0 
time complexity = (n*m ) * (n+m) space complexity = O(1)
       
       /*
        better approach= we can create two dummy array outside matrix 
         time complexity = (n*m) +(n*m)
            space complexity =o(n)+ o(m)
            
            */
      
        
        /*     optimal Approach = will use dummy array inside matrix first col =true 
              time complexity 2(n*m) space complexity=O(1) */
        int col0=1;
        
        for(int i=0; i<matrix.size(); i++)
        {
            if(matrix[i][0] ==0) col0=0;
            for(int j=1; j<matrix[0].size(); j++)
                if(matrix[i][j]==0)
                    matrix[i][0] = matrix[0][j]=0;
        }
        
        //traverse from back
        for(int i= matrix.size()-1; i>=0; i--)
        {
            for(int j=matrix[0].size()-1; j>=1; j--)
                if (matrix[i][0] ==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
            if(col0==0 ) matrix[i][0]=0;
        }
    }
    
    
 
