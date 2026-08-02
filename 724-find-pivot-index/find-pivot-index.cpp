class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        vector<int> rightSum(n, 0);
         
        
        for(int i = n - 1; i >= 0; i--){
            sum += nums[i];
            rightSum[i] = sum;
        }

        sum = 0;

        for(int i = 0; i < n; i++){
            if(sum == rightSum[i] - nums[i]) return i;
            sum += nums[i];
        }

        return -1;
    }
};