class CustomCompare {
public:
    bool operator()(pair<int, string> a, pair<int, string> b) const {
        if(a.first == b.first) 
        return a.second < b.second;
        else return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        priority_queue<
            pair<int, string>,
            vector<pair<int, string>>,
            CustomCompare
            > pq;

        unordered_map<string, int> mp;

        for(auto s : words) mp[s]++;

        for(const auto &[s, freq] : mp) {

            pq.push({freq, s});
            if(pq.size() > k) pq.pop();
        }

        vector<string> ans(k);
    
        while(!pq.empty()) {
            const auto x = pq.top(); pq.pop();
            ans[--k] = x.second;
        }

        return ans;
    }
};