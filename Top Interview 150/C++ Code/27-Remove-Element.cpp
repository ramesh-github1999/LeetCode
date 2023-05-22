// Time: O(n)
// Space: O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int next=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[next++]=nums[i];
            }
        }
        return next;
        
    }
};
