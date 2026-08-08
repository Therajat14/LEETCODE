class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int j = 0;

        for(int i = 0; i < n; i++){

            if (mp.count(nums[i]))
                return true;

            mp[nums[i]] = i;

            if (i - j + 1 > k) {
                mp.erase(nums[j]);
                j++;
            }
        }

        return false;
    }
};