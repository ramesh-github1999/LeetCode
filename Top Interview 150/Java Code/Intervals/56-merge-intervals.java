class Solution {
    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals,(a,b)->Integer.compare(a[0],b[0]));
        ArrayList<int[]>ans=new ArrayList<>();
        int f=intervals[0][0],s=intervals[0][1];     
        int n=intervals.length;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=s) s=Math.max(intervals[i][1],s);
            else {
                ans.add(new int [] {f,s});
                f=intervals[i][0];
                s=intervals[i][1];
            }
        }
        ans.add(new int [] {f,s});
        return ans.toArray(new int [ans.size()][2]);
    }
}


class Solution2 {
    public int[][] merge(int[][] nums) {
       Arrays.sort(nums, (a, b) -> Integer.compare(a[0], b[0]));
        List<int[]> merged = new ArrayList<>();
        merged.add(nums[0]);
        
        for (int i = 1; i < nums.length; i++) {
            if (merged.get(merged.size() - 1)[1] < nums[i][0]) {
                merged.add(nums[i]);
            } else {
                merged.get(merged.size() - 1)[1] = Math.max(merged.get(merged.size() - 1)[1], nums[i][1]);
            }
        }
        
        return merged.toArray(new int[merged.size()][]);
    }
}
