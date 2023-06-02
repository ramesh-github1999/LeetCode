class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;int first,second;bool flag=false;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            first=nums[i];
            while(i+1<n && nums[i+1]==nums[i]+1){
                second=nums[i+1];
                flag=true;
                i++;
            }
            if(flag==true) {
                string s=to_string(first);
                s+="->";
                s+=to_string(second);
                ans.push_back(s);
               flag=false;
            }
            else ans.push_back(to_string(first));
                
        }
        return ans;
    }
};
