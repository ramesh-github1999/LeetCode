 // topological sort code 
 // check cycle in Directed graph
class Solution {
    public boolean canFinish(int n, int[][] v) {
        List<List<Integer>>graph=new ArrayList<>();
        for(int i=0;i<n;i++){
            graph.add(new ArrayList<>());
        }
        int [] indegree=new int[n];
        for(int []it:v){
            graph.get(it[1]).add(it[0]);
            indegree[it[0]]++;
        }
        int cnt=0;
        Queue<Integer>q=new LinkedList<>();
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.add(i);
        }
        while(q.size()>0){
            int u=q.poll();
            for(int k:graph.get(u)){
                indegree[k]--;
                if(indegree[k]==0) q.add(k);
            }
            cnt++;
        }
        
        return cnt==n;
    }
}
