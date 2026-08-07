class Solution {
public:

    vector<int> dsu;

    int find(int x){
        if(dsu[x] < 0) return x;
        return dsu[x] = find(dsu[x]);
    }

    void unionSet(int u, int v){
        int pu = find(u); 
        int pv = find(v);

        if(pu == pv) return;
        
    }

    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        queue<pair<int, int>> q;
        q.push({i, j});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!q.empty()){  
            auto [x,y] = q.front(); q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] == '0') 
                    continue;
                
                q.push({nx, ny});
                grid[nx][ny] = '0';
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                        bfs(grid, i, j, m, n);
                        count++;
                }
            }
        }

        return count;
    }
};