class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> heap;
        queue<pair<int, pair<int, char>>> cooldown;
        int n = s.size();

        vector<int> hash(26);
        for(auto c : s) {
            hash[c - 'a']++;
            if(hash[c - 'a'] > (n  + 1)/ 2) return "";
        }

        for(int i = 0; i < 26; i++){
           if(hash[i]) heap.push({hash[i], i + 'a'});
        }

        int i = 0;
        string ans = "";

        while(!heap.empty() || !cooldown.empty()){

            if(cooldown.front().first == i) {
                heap.push(cooldown.front().second);
                cooldown.pop();
            }

            if(!heap.empty()){
                auto p = heap.top(); heap.pop();
                ans += p.second;

                if(p.first - 1 > 0){
                    cooldown.push({i + 1 + 1, {p.first - 1, p.second}});
                }
            }

            i++;
        }

        return ans;
    }
};