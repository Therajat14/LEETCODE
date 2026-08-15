class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {

        vector<vector<int>> ans;

        int x = newInterval[0];
        int y = newInterval[1];

        int i = 0;
        int n = intervals.size();

        // Intervals completely before newInterval
        while (i < n && intervals[i][1] < x) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals
        while (i < n && intervals[i][0] <= y) {
            x = min(x, intervals[i][0]);
            y = max(y, intervals[i][1]);
            i++;
        }

        // Add merged interval
        ans.push_back({x, y});

        // Remaining intervals
        while (i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};