class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int n = s.size();

        vector<int> hash(3,-1);
        
        for(int right = 0; right < n; right++){
            hash[s[right] - 'a'] = right;

            int sc = min(hash['a'-'a'], min(hash['b' - 'a'], hash['c' - 'a']));

            ans += 1 + sc;

           
        }

        return ans;
    }
};