class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> ltr(n, 1);
        vector<int> rtl(n, 1);

        for(int i = 0; i < n; i++){
            if(i - 1 >=0 && ratings[i - 1] < ratings[i])
                ltr[i] += ltr[i - 1];
        }
                
        int candy = 0;
        int right = 1;

        for(int i = n - 1; i >= 0; i--){
            if(i + 1 < n && ratings[i + 1] < ratings[i]){
                right = right + 1;
            }
            else right = 1;


            candy += max(ltr[i], right);
        }



        return candy;
    }
};