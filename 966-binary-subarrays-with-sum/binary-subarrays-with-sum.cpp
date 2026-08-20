class Solution {
public:
    int countSubarr(vector<int> &nums, int goal){
        if(goal < 0) return 0;

        int n = nums.size();
        int start  = 0;
        int end = 0; 
        int sum = 0;
        int ans = 0;

        while(end < n){
            sum += nums[end];

            while(sum > goal){

                sum -= nums[start];
                start++;
            }

            ans += end - start + 1;
            end++;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

            return  countSubarr(nums, goal) - countSubarr(nums, goal - 1);
    }
};