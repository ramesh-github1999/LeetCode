//Time : O((n+m)log(n+m))
// Space: o(n)
//
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++)
            nums1[i+m]=nums2[i];
        sort(nums1.begin(),nums1.end());
        
    }
};

//Time: O(m+n)
//space: O(m)

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums;
        for(int i=0;i<m;i++) nums.push_back(nums1[i]);
        int i=0,j=0;
        int cnt=0;
        int k=0;
        while(i<m && j<n){
            if(nums[i]<=nums2[j]){ nums1[k++]=nums[i];i++;}
            else nums1[k++]=nums2[j++];
        }
        while(i!=m){
          nums1[k++]=nums[i++];
        }
        while(j!=n) nums1[k++]=nums2[j++];
    }
};

// Time: O(m+n)
// Space: O(1)
class Solution3 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       
        int i=m-1,j=n-1;
       if(n==0) return;
        if(m==0) {
            for(int i=0;i<n;i++) nums1[i]=nums2[i];
        }
        for(int k=m+n-1;k>=0;k--){
            if(j<0) break;
            if(i>=0 && nums1[i]>nums2[j]) nums1[k]=nums1[i--];
            else  nums1[k]=nums2[j--];
        }
       
    }
};

