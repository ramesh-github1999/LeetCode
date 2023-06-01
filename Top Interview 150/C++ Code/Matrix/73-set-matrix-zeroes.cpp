// Time: O(m*n)
// space: O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int colo=1;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0) {if(matrix[i][j]==0) colo=0;}
                else {
                    if(matrix[i][j]==0) {matrix[i][0]=0;matrix[0][j]=0;}
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=1;j--){
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
            if(colo==0) matrix[i][0]=0;
        }
        
    }
};
