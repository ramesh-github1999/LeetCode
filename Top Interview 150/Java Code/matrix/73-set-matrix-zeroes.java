// Time: O(m*n)
// space : O(m+n)
class Solution {
    public void setZeroes(int[][] matrix) {
        Set<Integer>s1=new HashSet<>();
        Set<Integer>s2=new HashSet<>();
        int m=matrix.length;
        int n=matrix[0].length;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    s1.add(i);
                    s2.add(j);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                if(s1.contains(i) || s2.contains(j)) matrix[i][j]=0;
        }
    }
}


// space: O(1)
// time: O(M*N)
class Solution2 {
    public void setZeroes(int[][] matrix) {
        int col0=1;
        int m=matrix.length;
        int n=matrix[0].length;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(j==0) col0=0;
                    else {
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
        }
        if(col0==0){
           for(int i=0;i<m;i++)
                matrix[i][0]=0;
       }       
            
    }
}


class Solution3 {
    public void setZeroes(int[][] matrix) {
        int col0=1;
        int m=matrix.length;
        int n=matrix[0].length;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(j==0) col0=0;
                    else {
                        matrix[0][j]=0;
                        matrix[i][0]=0;
                    }
                }
            }
        }
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
            if(col0==0) matrix[i][0]=0;
        } 
            
    }
}




