class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > tasksHeap;

        for (int i = 0; i < n; i++)
            tasksHeap.push({tasks[i][0], tasks[i][1], i});

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > availableTasks;

        long long time = 0;
        vector<int> ans;

        while (!tasksHeap.empty() || !availableTasks.empty()) {

            // Jump to next arrival if CPU is idle
            if (availableTasks.empty() && time < tasksHeap.top()[0])
                time = tasksHeap.top()[0];

            // Add all tasks that have arrived
            while (!tasksHeap.empty() && tasksHeap.top()[0] <= time) {
                availableTasks.push({tasksHeap.top()[1], tasksHeap.top()[2]});
                tasksHeap.pop();
            }

            // Execute shortest task
            if (!availableTasks.empty()) {
                auto [processingTime, index] = availableTasks.top();
                availableTasks.pop();

                ans.push_back(index);
                time += processingTime;
            }
        }

        return ans;
    }
};