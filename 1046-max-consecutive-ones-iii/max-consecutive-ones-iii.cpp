class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int zeros = 0;
        int n = nums.size(); 
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) zeros++;
            

            if(zeros < k + 1){
             ans = max(ans, i  + 1 - start);
            }
            else {
                while(zeros > k){
                    if(nums[start] == 0) zeros--;
                    start++;
                }
            }
        }

        return  ans;
    }
};