class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> hash(26);
        int interval = 0;

        for(int i = 0; i < tasks.size(); i++){
            hash[tasks[i] - 'A']++;
        }

        priority_queue<pair<int, char>> heap;

        for(int i = 0; i < 26; i++) 
           if(hash[i]) heap.push({hash[i], i + 'A'}); 

        queue<pair<int , pair<int, char>>> cooldown;

        while(!heap.empty() || !cooldown.empty()){

            if(!heap.empty()){
                auto p = heap.top(); heap.pop();
                if(p.first - 1 > 0) 
                    cooldown.push({interval + n  , {p.first - 1, p.second}});
            }

            if(!cooldown.empty() && cooldown.front().first == interval){
                heap.push(cooldown.front().second); 
                cooldown.pop();            
            }

            interval++;
        }
        return interval;
    }
};

