// binary search O(log n)
class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return x;
        long long int l=1,h=x/2;
        while(l<=h){
            int mid=(l+h)/2;
            if(mid==x/mid) return mid;
           else if(mid>x/mid) h=mid-1;
            else l=mid+1;
        }
        return h;
    }
};
