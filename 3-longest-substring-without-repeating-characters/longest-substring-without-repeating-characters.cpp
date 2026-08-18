class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int start = 0;
        int n = s.size();
        int maxSize = 0;

        for(int end = 0; end < n; end++){
            char c = s[end];
            
            if(hash[c] != -1 && hash[c] >= start){
                    start = hash[c] + 1;
                    hash[c] = end;
            }else {
                hash[c] = end;
            }

            maxSize = max(end - start + 1, maxSize);
        }

        return maxSize;
    }
};