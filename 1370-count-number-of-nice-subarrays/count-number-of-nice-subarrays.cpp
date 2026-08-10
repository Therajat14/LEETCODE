class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int start = 0;
        int n = nums.size();
        int odd = 0;
        int ans = 0;
        mp[0] = 1;

        for(int end = 0; end < n; end++){
            if(nums[end] % 2 == 1) odd++;
            int req = odd - k;
            if(mp[req]) ans += mp[req];
            mp[odd]++;
        }

        return ans;
    }
};