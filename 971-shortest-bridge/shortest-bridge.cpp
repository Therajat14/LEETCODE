class Solution {
public:
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};

    int n;

    queue<pair<int, int>> qe;

    void bfs(vector<vector<int>> &grid, int i, int j, int k){

        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -k;

        if(k == 1)
        qe.push({i, j});

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();

            for(int i = 0; i < 4; i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 1){
                    cout << "hi";
                    grid[nx][ny] = -k;
                    cout <<  " " << k;
                    if(k == 1) qe.push({nx,ny});
                    q.push({nx, ny});
                }
            }
        }
    }

    int findans(vector<vector<int>>& grid){
        int k = 1;

        cout << qe.size();

        while(!qe.empty()){
            

            int p = qe.size();
            

            for(int i = 0; i < p; i++){

              auto [x, y] = qe.front(); qe.pop();

                for(int i = 0; i < 4; i ++){
                    int nx = dx[i] + x;
                    int ny = dy[i] + y;
                        
                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] != -1){
                        if(grid[nx][ny] == -2) return k - 1;
                        else{
                             qe.push({nx, ny});
                             grid[nx][ny] = -1;
                        }
                    }
                }
            }
            k++;
        }

        return 0;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        int k = 1;

    for(int i = 0; i < n && k <= 2; i++){
        for(int j = 0; j < n && k <= 2; j++){
            if(grid[i][j] == 1){
                bfs(grid, i, j, k++);
            }
        }
    }
        return findans(grid);
    }
};