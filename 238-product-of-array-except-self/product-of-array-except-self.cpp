class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixPrd(n);
        vector<int> postfixPrd(n);


        postfixPrd[n-1] = 1;
        for(int i = n-1; i > 0; i--){
            postfixPrd[i - 1] = postfixPrd[i] * nums[i]; 
        }

        prefixPrd[0] = 1;
        for(int i =  0; i < n -1; i++){
            prefixPrd[i + 1] = prefixPrd[i] * nums[i]; 
        }

        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            ans[i] = prefixPrd[i] * postfixPrd[i];
        }

        return ans;
    }
};