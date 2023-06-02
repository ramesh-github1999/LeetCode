class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(ans.back()[1]<intervals[i][0]) ans.push_back(intervals[i]);
            else ans.back()[1]=max(ans.back()[1],intervals[i][1]);
        }
        return ans;
    }
};


class Solution2 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& v) {
        vector<vector<int>>ans;
        int i=0;
        int n=intervals.size();
       while(i<n && intervals[i][1]<v[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=v[1]){
            v[0]=min(intervals[i][0],v[0]);
            v[1]=max(intervals[i][1],v[1]);
            i++;
        }
        ans.push_back(v);
        while(i<n)  ans.push_back(intervals[i]),i++;
        return ans;
    }
};
