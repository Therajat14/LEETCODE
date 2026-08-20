class Solution {
public:
    int atmostK(vector<int>& nums, int k){
        unordered_map<int, int> mp;
        int start = 0;
        int end = 0;
        int ans = 0;
        int n = nums.size();

        while(end < n){
            mp[nums[end]]++;

            while(mp.size() > k){
                mp[nums[start]]--;
                if(mp[nums[start]] == 0) mp.erase(nums[start]);
                start++;
            }
            
            ans += end - start + 1;

            end++;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return atmostK(nums,  k) - 
               atmostK(nums,  k - 1);
    }
};