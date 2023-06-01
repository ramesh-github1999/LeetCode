class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    // reverse and take transpose.
        reverse(matrix.begin(),matrix.end());
        for(int i=0;i<matrix.size();i++){
            for(int j=i+1;j<matrix[0].size();j++)
                swap(matrix[i][j],matrix[j][i]);
        }
    }
};


class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        // reverse the array
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                int temp=matrix[i][j];
               matrix[i][j]= matrix[n-i-1][j];
                 matrix[n-i-1][j]=temp;
            }
        }
        // Transpose
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        
    }
};
