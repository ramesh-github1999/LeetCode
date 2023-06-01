// Time:O(m*n)
// space:O(1)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int>v;
         int n=a.size();
        int m=a[0].size();
        int minc=0,minr=0,maxr=n-1,maxc=m-1;
        int count=0;
        int total=m*n;
        while(count<total){
            // top
             for(int i=minr,j=minc ;j<=maxc && count<total;j++){
                 v.push_back(a[i][j]);
                 count++;
             }
            minr++;
            // right
            for(int i=minr,j=maxc ;i<=maxr && count<total;i++){
                 v.push_back(a[i][j]);
                 count++;
             }
            maxc--;
            // bottom side
            for(int i=maxr,j=maxc ;j>=minc && count<total;j--){
                 v.push_back(a[i][j]);
                 count++;
             }
            maxr--;
            // left side
            for(int i=maxr,j=minc;i>=minr && count<total;i--){
                 v.push_back(a[i][j]);
                 count++;
             }
            minc++;
            
        }
        return v;
    }
};
