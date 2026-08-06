class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();

        // Add original index to each task
        for (int i = 0; i < n; i++)
            tasks[i].push_back(i);

        // Sort by enqueue time
        sort(tasks.begin(), tasks.end());

        // {processingTime, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > available;

        vector<int> ans;

        long long time = 0;
        int i = 0;

        while (i < n || !available.empty()) {

            // CPU idle -> jump to next task arrival
            if (available.empty() && time < tasks[i][0])
                time = tasks[i][0];

            // Add every task that has arrived
            while (i < n && tasks[i][0] <= time) {
                available.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            // Execute shortest task
            auto [processingTime, index] = available.top();
            available.pop();

            ans.push_back(index);
            time += processingTime;
        }

        return ans;
    }
};