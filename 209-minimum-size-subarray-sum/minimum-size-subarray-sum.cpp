class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int ans = INT_MAX;
        int n = nums.size();
        int sum = 0;

        for(int end = 0; end < n; end++){
            sum += nums[end];              

            while(sum >= target){
                ans = min(end - start  + 1, ans);
                sum -= nums[start++];   
            }

        }

        return ans == INT_MAX ? 0 : ans;
    }
};