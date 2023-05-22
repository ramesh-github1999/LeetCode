// Time:O(nlogn)
//Space:O(1)
// Using sorting

class Solution {
    public int majorityElement(int[] nums) {
        Arrays.sort(nums);
        return nums[nums.length/2];
    }
}

// Time:O(n)
//Space:O(n)
// Using HashMap
class Solution2 {
    public int majorityElement(int[] nums) {
        Map<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<nums.length;i++){
           if(!mp.containsKey(nums[i])) mp.put(nums[i],1);
            else mp.put(nums[i],mp.get(nums[i])+1);
        }
        int ans=0;int cnt=0;
        for(int x:mp.keySet()){
            int k=mp.get(x);
            if(k>cnt){
                ans=x;
                cnt=k;
            }
        }
        
        return ans;
    }
}

// Time:O(n)
// Space: O(1)
// Boyer-Moore Voting Algorithm (Imp.)

class Solution3 {
    public int majorityElement(int[] nums) {
        int ans=Integer.MIN_VALUE;
        int cnt=0;
        for(int i=0;i<nums.length;i++){
            if(cnt==0) {
                ans=nums[i];
                cnt++;
            }
            else if(nums[i]==ans) cnt++;
            else cnt--;
            
        }
        return ans;
        
    }
}
