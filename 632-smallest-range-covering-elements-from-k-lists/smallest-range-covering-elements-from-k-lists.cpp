class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> sorted;
        int n = nums.size();

        priority_queue<
            vector<int>, 
            vector<vector<int>>, 
            greater<vector<int>>> pq;


        for(int i = 0; i < n; i++){
            pq.push({nums[i][0],i,0});
        }

       

        while(!pq.empty()){
            auto p = pq.top(); pq.pop();
            int val = p[0];
            int row = p[1];
            int col = p[2];

            sorted.push_back({val, row});
            if(col + 1 < nums[row].size()) pq.push({nums[row][col + 1], row , col + 1});
        }
        unordered_map<int,int> freq;
        int k = nums.size();

        int left = 0;
        int covered = 0;

        int bestL = 0;
        int bestR = INT_MAX;

        for(int right = 0; right < sorted.size(); right++){

            int row = sorted[right].second;

            if(++freq[row] == 1)
                covered++;

            while(covered == k){

                int L = sorted[left].first;
                int R = sorted[right].first;

                if(R - L < bestR - bestL){
                    bestL = L;
                    bestR = R;
                }

                int leftRow = sorted[left].second;

                if(--freq[leftRow] == 0){
                    freq.erase(leftRow);
                    covered--;
                }

                left++;
            }
        }

        return {bestL, bestR};
    }
};