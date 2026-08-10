class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> hash(26);
        int start = 0;
        int n = s1.size();
        int m = s2.size();

        for(int i = 0; i < n; i++){
            hash[s1[i] - 'a']++;
        }

        for(int end = 0; end < m; end++){
            hash[s2[end] - 'a']--;

            if(end - start + 1 == n){
                bool flag = true;

                for(int i = 0; i < 26; i++){
                    if(hash[i]) {
                        flag = false;
                        break;
                        }
                    
                }

                if(flag) return true;
                hash[s2[start] - 'a']++;
                start++;
            }
        }
        return false;
    }
};