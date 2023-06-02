class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> ans = new ArrayList<>();
        int first;
        int second=0;
        boolean flag = false;
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            first = nums[i];  
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                second = nums[i + 1];
                flag = true;
                i++;
            }
            
            if (flag) {
                String s = ""+first + "->" + second;
                ans.add(s);
                flag = false;
            } else {
                ans.add(""+first);
            }
        }
        
        return ans;
    }
}
