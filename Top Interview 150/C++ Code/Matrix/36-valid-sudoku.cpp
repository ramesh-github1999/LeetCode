class Solution {
public:
    bool check(vector<vector<char>>v,int i,int j){
        char c=v[i][j];
        for(int x=0;x<9;x++){
            if(x!=j && v[i][x]==c) return false;
        }
         for(int x=0;x<9;x++){
            if(x!=i && v[x][j]==c) return false;
        }
        int ix=i/3*3;
        int iy=j/3*3;
          for(int x=0;x<3;x++){
              for(int y=0;y<3;y++){
                  if(x+ix==i && y+iy==j) continue;
                  else if(v[x+ix][y+iy]=='.') continue;
                  else if(v[x+ix][y+iy]==c) return false;
              }
          }
        return true;
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {
     for(int i=0;i<9;i++){
         for(int j=0;j<9;j++){
             if(board[i][j]!='.'){
                 if(check(board,i,j)==false) return false;
             }
         }
     }
        return true;
        
    }
};
