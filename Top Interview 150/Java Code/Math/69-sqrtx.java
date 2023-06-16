// Binary Search O(log n)
class Solution {
    public int mySqrt(int x) {
         if(x==1) return x;
         int l=1,h=x/2;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(mid==x/mid) return mid;
           else if(mid>x/mid) h=mid-1;
            else l=mid+1;
        }
        return h;
    }
}
