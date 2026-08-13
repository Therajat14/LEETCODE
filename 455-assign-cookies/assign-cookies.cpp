class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
    
        int j = 0;

        if(n == 0) return 0;
        int count = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        for(int i = 0; i < m; i++){
        
            if(j >= n) return count;

            while( j < n && s[j] < g[i]) j++;
            if(j < n){
                count ++; j++;
            }
        }

        return m;
    }
};