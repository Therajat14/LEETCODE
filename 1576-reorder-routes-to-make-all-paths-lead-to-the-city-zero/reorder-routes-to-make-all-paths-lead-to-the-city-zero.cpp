class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {

        vector<vector<int>> graph(n);
        unordered_set<long long> dir;

        for(int i = 0; i < connections.size(); i ++){

            int u = connections[i][0];
            int v = connections[i][1];

            graph[u].push_back(v);
            graph[v].push_back(u);

            dir.insert(1LL * u * n + v);
        }

        queue<int> q;
        q.push(0);

        vector<bool> vis(n);
        vis[0] = true;

        int count = 0;

        while(!q.empty()){
            auto node = q.front(); q.pop();

            for(int i = 0; i < graph[node].size(); i++){
                int next = graph[node][i];

                if(!vis[next]){
                    vis[next] = 1;
                    q.push(next);
                    if(!dir.count(1LL * n * next + node)) count ++;
                }
            }

        }

        return count;
    }
};