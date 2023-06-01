// Time:O(m*n)
// space:O(1)
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer>list=new ArrayList<>();
        int m=matrix.length;
        int n=matrix[0].length;
        int minc=0,minr=0,maxr=m-1,maxc=n-1;
        int cnt=0;int total=m*n;
        while(cnt<total){
            // top
            for(int i=minr,j=minc;j<=maxc && cnt<total;j++){
                list.add(matrix[i][j]);
                cnt++;
            }
            minr++;
            //right wall
            for(int i=minr,j=maxc;i<=maxr && cnt<total;i++){
                 list.add(matrix[i][j]);
                cnt++;
            }
            maxc--;
            // bottom
             for(int i=maxr,j=maxc;j>=minc  && cnt<total;j--){
                 list.add(matrix[i][j]);
                cnt++;
            }
            maxr--;
            // left
            for(int i=maxr,j=minc;i>=minr  && cnt<total;i--){
                list.add(matrix[i][j]);
                cnt++;
            }
            minc++;
            
        }
        return list;

    }
}
