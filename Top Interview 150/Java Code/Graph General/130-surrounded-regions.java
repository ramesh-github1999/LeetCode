class Solution {
    public void dfs(char[][] v,int i,int j){
        if(i<0 || i>=v.length || j<0 || j>=v[0].length || v[i][j]=='X' || v[i][j]=='K') return;
        v[i][j]='K';
        dfs(v,i+1,j);
        dfs(v,i-1,j);
        dfs(v,i,j-1);
        dfs(v,i,j+1);
    }
    
    public void solve(char[][] v) {
         int n=v.length;
        int m=v[0].length;
        // first row and last row
        for(int j=0;j<m;j++){
            dfs(v,0,j);
            dfs(v,n-1,j);
        }
        // first column and last column
        for(int i=0;i<n;i++){
            dfs(v,i,0);
            dfs(v,i,m-1);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]=='K') v[i][j]='O';
                else if(v[i][j]=='O') v[i][j]='X';
            }
        }
    }
}
