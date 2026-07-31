class Solution {
public:

    vector<int> dsu;

    void unionSet(int u, int v){
        int pu = find(u);
        int pv = find(v);

        if(pv == pu) return;

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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        dsu = vector<int>(n, -1);
        for(auto edge : edges) unionSet(edge[0], edge[1]);

        cout << dsu[source] << " " << dsu[destination];

        return find(source) == find(destination);
    }
};