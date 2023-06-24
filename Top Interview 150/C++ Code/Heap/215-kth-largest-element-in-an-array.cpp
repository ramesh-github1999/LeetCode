class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // using min heap
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // using max heap
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
