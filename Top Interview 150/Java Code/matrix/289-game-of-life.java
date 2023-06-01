// Space: O(m*n)
class Solution {
    int countLive(int [][] v,int i,int j){
         int cnt=0;
        int m=v.length;
        int n=v[0].length;
        for(int k=i-1;k<=i+1;k++){
            for(int l=j-1;l<=j+1;l++){
                if(k==i && l==j) continue;
                if(k>=0 && k<m && l>=0 && l<n) if(v[k][l]==1) cnt++;
            }
        } 
        return cnt;
    }
    
    public void gameOfLife(int[][] board) {
        int m=board.length;
        int n=board[0].length;
        int [][] v=new int [m][n];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    int cnt= countLive(board,i,j);
                    if(cnt==2 || cnt==3) v[i][j]=1;
                    else v[i][j]=0;
                }
                else{
                     int cnt= countLive(board,i,j);
                     if(cnt==3) v[i][j]=1;
                }
                
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                board[i][j]=v[i][j];
        }
        
    }
}


// Space:O(1)
class Solution2 {
    int countLive(int [][] v,int i,int j){
         int cnt=0;
        int m=v.length;
        int n=v[0].length;
        for(int k=i-1;k<=i+1;k++){
            for(int l=j-1;l<=j+1;l++){
                if(k==i && l==j) continue;
                if(k>=0 && k<m && l>=0 && l<n) if(Math.abs(v[k][l])==1) cnt++;
            }
        } 
        return cnt;
    }
    
    public void gameOfLife(int[][] board) {
        int m=board.length;
        int n=board[0].length;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    int cnt= countLive(board,i,j);
                    if(cnt!=2 && cnt!=3) board[i][j]=-1; // changed to 0;
                }
                else{
                     int cnt= countLive(board,i,j);
                     if(cnt==3) board[i][j]=2; // changed to 1
                }
                
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==2) board[i][j]=1;
                if(board[i][j]==-1) board[i][j]=0;
            }
        }
    }
}
