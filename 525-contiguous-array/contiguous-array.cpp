class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int>mp;

        int prefix = 0;
        int n = nums.size();
        int maxSize = 0;
        mp[0] = 0;

        for(int i = 0; i < n; i++){
            prefix += nums[i] ? 1 : -1;
            if(mp.count(prefix)) maxSize = max(maxSize, i + 1 - mp[prefix]);
            else mp[prefix] = i+1;
        }

        return maxSize;
    }
};