class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        mp[0] = 1;
        int ans = 0;

        for(int i = 0; i  < n; i++){
            sum += nums[i];
            int req =  sum  - goal;
            if(mp.count(req)){
                ans += mp[req];
            }
            mp[sum]++;
        }

        return ans;

    }
};