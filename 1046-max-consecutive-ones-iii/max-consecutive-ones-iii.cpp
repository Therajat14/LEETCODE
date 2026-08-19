class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        int zeros = 0;
        int n = nums.size(); 
        int ans = 0;

        while(end < n){
            if(nums[end] == 0) zeros++;

            if(zeros > k){
                if(nums[start] == 0) zeros--;
                start++;
            }

           if(zeros <= k){
            ans = max(ans, end - start + 1);
           }

           end++;

        }

        return  ans;
    }
};