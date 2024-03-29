// Space: O(m*n)
class Solution {
public:
    int countLive(vector<vector<int>>&v,int i,int j){
        int cnt=0;
        int m=v.size();
        int n=v[0].size();
                if(i-1>=0 && v[i-1][j]==1) cnt++;
                if(i+1<m && v[i+1][j]==1) cnt++;
                if(j-1>=0 && v[i][j-1]==1) cnt++;
                if(j+1<n && v[i][j+1]==1) cnt++;
                if(i+1<m && j-1>=0 && v[i+1][j-1]==1) cnt++;
                if(i-1>=0 && j+1<n && v[i-1][j+1]==1) cnt++;
                if(i-1>=0 && j-1>=0 && v[i-1][j-1]==1) cnt++;
                if(i+1<m && j+1<n && v[i+1][j+1]==1) cnt++;
       return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>v=board;
         int m=v.size();
        int n=v[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    int cnt= countLive(board,i,j);
                    if(cnt!=2 && cnt!=3) v[i][j]=0;
                }
                else{
                     int cnt= countLive(board,i,j);
                     if(cnt==3) v[i][j]=1;
                }
                
            }
        }
        board=v;
    }
};


// space: O(m*n)
class Solution2 {
public:
    int countLive(vector<vector<int>>&v,int i,int j){
        int cnt=0;
        int m=v.size();
        int n=v[0].size();
        for(int k=i-1;k<=i+1;k++){
            for(int l=j-1;l<=j+1;l++){
                if(k==i && l==j) continue;
                if(k>=0 && k<m && l>=0 && l<n) if(v[k][l]==1) cnt++;
            }
        }
        return cnt;
    }
   
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>v=board;
         int m=v.size();
        int n=v[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    int cnt= countLive(board,i,j);
                    if(cnt!=2 && cnt!=3) v[i][j]=0;
                }
                else{
                     int cnt= countLive(board,i,j);
                     if(cnt==3) v[i][j]=1;
                }
                
            }
        }
        board=v;
    }
};


// Space :O(1)
class Solution3 {
public:
    int countLive(vector<vector<int>>&v,int i,int j){
        int cnt=0;
        int m=v.size();
        int n=v[0].size();
        for(int k=i-1;k<=i+1;k++){
            for(int l=j-1;l<=j+1;l++){
                if(k==i && l==j) continue;
                if(k>=0 && k<m && l>=0 && l<n) if(abs(v[k][l])==1) cnt++;
            }
        } 
        return cnt;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
         int m=board.size();
        int n=board[0].size();
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
};
