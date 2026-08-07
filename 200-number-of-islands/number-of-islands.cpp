class Solution {
public:
    vector<int> dsu;

    int find(int x) {
        if (dsu[x] < 0)
            return x;

        return dsu[x] = find(dsu[x]);
    }

    void unionSet(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        
        if (dsu[pu] < dsu[pv]) {
            dsu[pu] += dsu[pv];
            dsu[pv] = pu;
        } else {
            dsu[pv] += dsu[pu];
            dsu[pu] = pv;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dsu.assign(m * n, -1);

        int islands = 0;

        // Count all land cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1')
                    islands++;
            }
        }

        // Only check right and down
        int dx[2] = {1, 0};
        int dy[2] = {0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '0')
                    continue;

                int id1 = i * n + j;

                for (int k = 0; k < 2; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= m || ny >= n)
                        continue;

                    if (grid[nx][ny] == '0')
                        continue;

                    int id2 = nx * n + ny;

                    if (find(id1) != find(id2)) {
                        unionSet(id1, id2);
                        islands--;
                    }
                }
            }
        }

        return islands;
    }
};