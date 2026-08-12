class Solution {
public:
    static bool compare(vector<int> a, vector<int> b) {
        return a[1] > b[1];   
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        sort(boxTypes.begin(), boxTypes.end(), compare);
        int n = boxTypes.size();

        int ans = 0;
        int boxes = 0;
        int i  = 0;

        for(i = 0; i < n; i++){
            if(boxes + boxTypes[i][0] > truckSize ) break;
            boxes += boxTypes[i][0];
            ans += boxTypes[i][0] * boxTypes[i][1];
        }

        if(boxes == truckSize || i == n) return ans;
        int req = truckSize - boxes;
        boxes +=  req;
        ans += req *  boxTypes[i][1];

        return ans;
    }
};