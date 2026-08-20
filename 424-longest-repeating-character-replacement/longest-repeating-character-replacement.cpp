class Solution {
public:
    int characterReplacement(string s, int k) {

        int n  = s.size();
        int start = 0;

        vector<int> hash(26);
        int maxL = 0;

        for(int end = 0; end  < n; end++){
            char c = s[end];

            hash[c - 'A']++;
            int maxC = 0;

            for(int i = 0; i < 26; i++)
                maxC  = max(maxC, hash[i]);

            if(end - start + 1 > maxC + k){
                     hash[s[start] - 'A']--;
                     start++;
                     maxC = 0;                     
                }
            

            maxL = max(maxL, end - start + 1);
        }     

        return maxL;
    }
};