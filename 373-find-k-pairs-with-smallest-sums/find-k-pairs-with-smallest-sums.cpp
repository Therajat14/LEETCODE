class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
        > pq;

        int x = nums2.size();

        for(int i = 0; i < min(x, k); i++){
            pq.push({nums1[0] + nums2[i], 0, i});
        }

        vector<vector<int>> ans;

        while(ans.size() < k){
         auto temp = pq.top(); pq.pop();
         int x = temp[1];
         int y = temp[2];
         ans.push_back({nums1[x], nums2[y]});

        if(x + 1 < nums1.size()) 
            pq.push({nums1[x + 1] + nums2[y], x + 1, y});
            cout << x + 1 << " " << y << endl;
        }

        return ans;

    }
};