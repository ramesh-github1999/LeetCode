class Solution {
     // Time :O(m+n)
    // Space:o(1)
    
    int p1=0,p2=0;
    int getMin(int [] nums1,int [] nums2){
        if(p1<nums1.length && p2<nums2.length)
            return nums1[p1]<nums2[p2]?nums1[p1++]:nums2[p2++];
        else if(p1<nums1.length)
            return nums1[p1++];
        else if(p2<nums2.length) return nums2[p2++];
        return -1;
    }
    
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
         int m=nums1.length,n=nums2.length;
        if((m+n)%2!=0){
            for(int i=0;i<(m+n)/2;i++){
                int temp=getMin(nums1,nums2);
            }
            return getMin(nums1,nums2);
        }
        else{
            for(int i=0;i<(m+n)/2-1;i++){
                int temp=getMin(nums1,nums2);
            }
            return (double)(getMin(nums1,nums2)+getMin(nums1,nums2))/2;
            
        }
    }
}



//Time: O(log(m+n))
// Space:O(1)
class Solution {
    public double findMedianSortedArrays(int[] a, int[] b) {
        if (a.length > b.length) {
           int [] temp = a;
            a = b;
            b = temp;
        }
         int l = 0;
        int h = a.length;
        int te = a.length + b.length;

        while (l <= h) {
            int aleft = (l + h) / 2;
            int bleft = (te + 1) / 2 - aleft;

            int alm1 = (aleft == 0) ? Integer.MIN_VALUE : a[aleft - 1];
            int al = (aleft == a.length) ? Integer.MAX_VALUE : a[aleft];
            int blm1 = (bleft == 0) ? Integer.MIN_VALUE : b[bleft - 1];
            int bl = (bleft == b.length) ? Integer.MAX_VALUE : b[bleft];

            if (alm1 <= bl && al >= blm1) {
                if (te % 2 != 0)
                    return (double) Math.max(alm1, blm1);
                else {
                    int lmax = Math.max(alm1, blm1);
                    int rmin = Math.min(al, bl);
                    return (double) (lmax + rmin) / 2.0;
                }
            } else {
                if (al < blm1)
                    l = aleft + 1;
                else
                    h = aleft - 1;
            }
        }

        return 0.0;
        
    }
}
