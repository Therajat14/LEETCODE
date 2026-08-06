class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int original_color = image[sr][sc];
        if(original_color == color) return image;

        int m = image.size();
        int n = image[0].size();

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
    

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();

            for(int i = 0; i < 4; i++){
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if(nx >= 0 && ny >= 0 && nx < m && ny < n &&
                   image[nx][ny] == original_color){
                    image[nx][ny] = color;
                    q.push({nx, ny});
                   }
            }
        }

        return image;

    }
};