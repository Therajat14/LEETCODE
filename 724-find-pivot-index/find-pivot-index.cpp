class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int Rsum = 0;        
        
        for(int i = n - 1; i >= 0; i--){
            Rsum += nums[i];
        }

        int Lsum = 0;

        for(int i = 0; i < n; i++){
            if(Lsum == Rsum - nums[i]) return i;
            Lsum += nums[i];
            Rsum -= nums[i];
        }

        return -1;
    }
};