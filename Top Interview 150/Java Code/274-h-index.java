// Time: O(n)
// Space :O(n)
// https://www.youtube.com/watch?v=fVAR6SiATgI

class Solution {
    public int hIndex(int[] citations) {
        int n=citations.length;
        int [] v=new int [n+1];
        for(int i=0;i<n;i++){
            if(citations[i]>n) v[n]++;
            else v[citations[i]]++;
        }
        int count=0;
        for(int i=n;i>=0;i--){
            count+=v[i];
            if(count>=i) return i;
        }
        return 0;
    }
}
