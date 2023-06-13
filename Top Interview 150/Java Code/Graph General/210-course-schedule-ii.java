 // topological sort code 
   // check cycle in Directed graph
class Solution {
    public int[] findOrder(int n, int[][] v) {
        List<List<Integer>>graph=new ArrayList<>();
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
        }
        int [] indegree=new int[n];
        int [] ans=new int [n];
        for(int []it:v){
            graph.get(it[1]).add(it[0]);
            indegree[it[0]]++;
        }
        int cnt=0;
        int idx=0;
        Queue<Integer>q=new LinkedList<>();
        for(int i=0;i<n;i++){
            if(indegree[i]==0) {
                q.add(i);
                ans[idx++]=i;
            }
        }
        while(q.size()>0){
            int u=q.poll();
            for(int k:graph.get(u)){
                indegree[k]--;
                if(indegree[k]==0) {
                    q.add(k);
                    ans[idx++]=k;
                }
            }
            cnt++;
        }
        if(cnt!=n) return new int[0];
        return ans;
    }
}
