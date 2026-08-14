class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);

        int lastEndTime = intervals[0][0];
        int overlaps = 0;
        int n = intervals.size();

        for(auto interval : intervals){
            int s = interval[0];
            int e = interval[1];

            if(s >= lastEndTime){
                lastEndTime = e;
            }
            else {
                overlaps++;
            }
        }

        return overlaps;
    }
};