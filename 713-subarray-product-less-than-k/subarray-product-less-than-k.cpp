class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0;
        int ans = 0;
        int prd = 1;


        for(int end = 0; end < nums.size(); end++){
            prd *= nums[end];

            while(prd >= k && start <= end){
                prd /= nums[start++];
            }

            ans += end - start + 1;
        }

        return ans;
    }
};