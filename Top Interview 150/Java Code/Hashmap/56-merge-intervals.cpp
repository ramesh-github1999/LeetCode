class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int f=intervals[0][0];
        int s=intervals[0][1];
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=s) s=max(intervals[i][1],s);
            else {
                ans.push_back({f,s});
                f=intervals[i][0];
                s=intervals[i][1];
            }
        }
         ans.push_back({f,s});
        return ans;
    }
};


class Solution2 {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>v;
        v.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(v.back()[1]<nums[i][0]) v.push_back(nums[i]);
            else v.back()[1]=max(v.back()[1],nums[i][1]);
        }
        return v;
    }
};
