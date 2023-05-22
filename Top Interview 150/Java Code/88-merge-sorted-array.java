// Time: O((m+n)log(m+n))
//space : o(n)
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        for(int i=0;i<n;i++)
            nums1[i+m]=nums2[i];
        Arrays.sort(nums1);
    }
}

// Time: O(m+n)
// Space: O(m)
class Solution2 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=0,j=0;
        int k=0;
        int [] nums=new int[m];
        for(int x=0;x<m;x++) nums[x]=nums1[x];
        while(i<m && j<n){
            if(nums[i]<nums2[j]) nums1[k++]=nums[i++];
            else nums1[k++]=nums2[j++];
        }
        while(i<m) nums1[k++]=nums[i++];
        while(j<n) nums1[k++]=nums2[j++];
    }
}

// Time: O(m+n)
// Space: O(1)
class Solution3 {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i=m-1,j=n-1;
        for(int k=m+n-1;k>=0;k--){
            if(j<0) break;
            if(i>=0 && nums1[i]>nums2[j]) nums1[k]=nums1[i--];
            else nums1[k]=nums2[j--];
        }
    }
}
