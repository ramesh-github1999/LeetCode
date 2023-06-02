//Time :O(n)
//Space:O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
int n=nums.size();
        if(n==0) return 0;
        int best=1,count=1;
        set<int>s;
        for(int i=0;i<n;i++) s.insert(nums[i]);
        for(auto it:s){
            int i=it+1;
            if(s.count(i)){
                count++;
                best=max(best,count);
            }
            else count=1;
        }
        return best;
    }
};
