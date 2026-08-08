class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size(); 
        int sum = 0;

        for(int i = 0; i < k; i++){
            sum += cardPoints[i];
        }

        int i = k - 1;
        int j = n - 1;

        int maxSum = sum;

        while(i >= 0){
            sum -= cardPoints[i--];
            sum += cardPoints[j--];

            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};