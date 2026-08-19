class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int n;

    queue<pair<int, int>> iq;

    void getFirstLand(vector<vector<int>>& grid, int i, int j){
        queue<pair<int,int>> q;
        q.push({i, j});
        grid[i][j] = -1;
        iq.push({i, j});

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();

            for(int i = 0; i < 4; i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if(nx >= 0 && ny >= 0 && ny < n && nx < n && grid[nx][ny] == 1){
                    grid[nx][ny] = -1;
                    q.push({nx, ny});
                    iq.push({nx, ny});
                }
            }
        }
    }

    int multibfs(vector<vector<int>>& grid){

        int lvl = 0;

        while(!iq.empty()){
            int sz = iq.size();

            for(int i = 0; i < sz; i++){
                auto [x, y] = iq.front();
                iq.pop();

                for(int i = 0; i < 4; i++){
                
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if(nx >= 0 && ny >= 0 && ny < n && nx < n && grid[nx][ny] != -1){
                    if(grid[nx][ny] == 1) return lvl;
                    grid[nx][ny] = -1;
                    iq.push({nx, ny});
                }
                }
            }lvl++;
        }

        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        bool firstFound = false;

        for(int i = 0; i < n; i++){
            for(int  j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    getFirstLand(grid, i, j);
                    firstFound = true;
                    break;
                }
            }
            if(firstFound) break;
        }

    return multibfs(grid);
         
    }
};