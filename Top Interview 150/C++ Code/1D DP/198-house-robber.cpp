class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
         int maxi=max(nums[0],nums[1]);
        int preMaxi=nums[0];
        int dp[n];
        dp[0]=nums[0];
        dp[1]=nums[1];
        for(int i=2;i<n;i++){
            dp[i]=preMaxi+nums[i];
            maxi=max(maxi,dp[i]);
            preMaxi=max(preMaxi,dp[i-1]);
        }
        return maxi;
    }
};





class Solution {
public:
    int rob(vector<int>& nums) {
    // maximum sum of non adjacent element pepcoding
        int n=nums.size();
        if(n==1) return nums[0];
        int inc=nums[0],exe=0;
        for(int i=1;i<n;i++){
            int ninc=exe+nums[i];
            int nexe=max(inc,exe);
            inc=ninc;
            exe=nexe;
        }
        return max(exe,inc);
    }
};



class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int dp[n];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){ 
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
            
}
        return dp[n-1];
        }
};
