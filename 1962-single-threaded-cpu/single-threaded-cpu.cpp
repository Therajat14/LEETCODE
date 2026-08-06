class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        // {enqueueTime, processingTime, index}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > taskHeap;

        for (int i = 0; i < n; i++) {
            taskHeap.push({tasks[i][0], tasks[i][1], i});
        }

        // {processingTime, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > available;

        vector<int> ans;
        long long time = 0;

        while (!taskHeap.empty() || !available.empty()) {

            // If CPU is idle and no available task,
            // jump directly to the next task's arrival.
            if (available.empty() && time < taskHeap.top()[0]) {
                time = taskHeap.top()[0];
            }

            // Move every task that has already arrived.
            while (!taskHeap.empty() && taskHeap.top()[0] <= time) {
                available.push({taskHeap.top()[1], taskHeap.top()[2]});
                taskHeap.pop();
            }

            // Execute the shortest available task.
            if (!available.empty()) {
                auto [processingTime, index] = available.top();
                available.pop();

                ans.push_back(index);
                time += processingTime;
            }
        }

        return ans;
    }
};