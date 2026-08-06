class Solution {
public:

    vector<int> dsu;

    void unionSet(int u, int v){
        int pu = find(u);
        int pv = find(v);
        
        if(pu == pv) return;

        if(dsu[pu] < dsu[pv]) {
            dsu[pu] += dsu[pv];
            dsu[pv] = pu;
        }
        else {
            dsu[pv] += dsu[pu];
            dsu[pu] = pv;
        }
    }

    int find(int x){
        if(dsu[x] < 0) return x;
        return dsu[x] = find(dsu[x]);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        dsu = vector<int>(n, -1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j]) unionSet(i, j);
            }
        }

        unordered_set<int> s;

        for(int i = 0; i < n; i++) s.insert(find(i));

        return s.size();
    }
};