class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int ans = 0;
        int n = s.size();

        vector<int> hash(3,0);
        
        for(int right = 0; right < n; right++){
            hash[s[right] - 'a']++;

            while(hash[0] && hash[1] && hash[2]){
                ans+= n - right;
                hash[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};