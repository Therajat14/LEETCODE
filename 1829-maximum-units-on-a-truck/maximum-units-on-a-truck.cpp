class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b) {
        return a[1] > b[1];   
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(), compare);

        int ans = 0;
        int boxes = 0;

        for(auto box : boxTypes){
            int take  = min(truckSize, box[0]);
            ans += take * box[1];
            truckSize -= take;
        }

        return ans;
    }
};