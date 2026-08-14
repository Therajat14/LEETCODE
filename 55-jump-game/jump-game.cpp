class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxCover = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(maxCover < i) return false;

            maxCover  = max(i + nums[i], maxCover);

            if(maxCover >= n - 1) return true;
        }

        return false;
    }
};