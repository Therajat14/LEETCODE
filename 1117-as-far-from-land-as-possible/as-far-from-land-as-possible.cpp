class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>> q;

        // Put all land cells into the queue.
        // Distance of land = 0.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        int ans = -1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 &&
                    nx < n && ny < n &&
                    grid[nx][ny] == -1) {

                    grid[nx][ny] = grid[x][y] + 1;

                    ans = max(ans, grid[nx][ny]);

                    q.push({nx, ny});
                }
            }
        }

        return ans;
    }
};