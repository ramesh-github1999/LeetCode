// Time:O(nlogn)
//Space:O(1)
// Using sorting

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
        
    }
};

// Time:O(n)
//Space:O(n)
// Using map
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
          map<int,int> h;
        for(int i=0;i<n;i++){
            h[nums[i]]++;
          }
    for(int i:nums)
    {
        if(h[i]>n/2)
            return i;
    }
        return -1;
        
    }
};

// Time:O(n)
// Space: O(1)
// Boyer-Moore Voting Algorithm (Imp.)
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int ans=-1,count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0) {ans=nums[i],count=1;}
               else if(nums[i]==ans) count++;
                else count--;
            }
        
        return ans;
    }
};
