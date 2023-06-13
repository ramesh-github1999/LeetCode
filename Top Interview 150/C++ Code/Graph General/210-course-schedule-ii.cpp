class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<vector<int>>graph(n,vector<int>());
        vector<int>indegree(n,0);
        for(int i=0;i<v.size();i++){
            graph[v[i][1]].push_back(v[i][0]);
            indegree[v[i][0]]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) {
               q.push(i);
               ans.push_back(i);
            }
        }
        int cnt=0;
        while(q.size()){
            int u=q.front();
            q.pop();
            for(auto v:graph[u]){
                indegree[v]--;
                if(indegree[v]==0) {
                    q.push(v);
                    ans.push_back(v);
                }
            }
            cnt++;
        }
        if(cnt!=n) return {};
        return ans;
        
    }
};
