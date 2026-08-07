class Solution {
public:
    int bfs(vector<vector<int>>& grid, int i, int j, int m, int n){
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;
        int area = 1;

        while(!q.empty()){
            auto [x , y] = q.front(); q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= m || ny >= n || !grid[nx][ny]) continue;
                q.push({nx, ny});
                grid[nx][ny] = 0;
                area++;
            }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxArea = 0;

        for(int i = 0; i < m; i++){
            for(int j  = 0; j < n; j++){
                if(grid[i][j]) maxArea = max(maxArea, bfs(grid, i, j, m, n));
            }
        }

        return maxArea;
    }
};