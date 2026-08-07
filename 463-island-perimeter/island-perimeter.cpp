class Solution {
public:
    int perimeter = 0;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    void bfs(vector<vector<int>> &grid, int i, int j, int m, int n){
        queue<pair<int, int>> q;
        q.push({i, j});
        
        grid[i][j] = -1;

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();

            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx >= 0 && ny >= 0 && nx < m && ny < n ){
                    if(grid[nx][ny] == 1){
                    grid[nx][ny] = -1;
                    q.push({nx, ny});
                    }
                    else if(grid[nx][ny] == 0) perimeter++;
                }
                else if(!((nx >= 0 && ny >= 0 && nx < m && ny < n ))){
                    perimeter++;
                }
                
            }
        }


    }

    int islandPerimeter(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    bfs(grid, i, j, m, n);
                    return perimeter;

                }
            }
        }

        return perimeter;
    }
};