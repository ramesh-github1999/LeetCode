class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& nums) {
        int cnt=1;
        sort(nums.begin(),nums.end());
        bool flag=false;
        int back=nums[0][1];
        for(int i=1;i<nums.size();i++){
            if(back>=nums[i][0]) {
                back=min(nums[i][1],back);}
            else {
                cnt++;
                back=nums[i][1];
            }
        }
        return cnt;
    }
};
