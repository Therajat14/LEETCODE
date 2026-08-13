class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

         vector<int> account(3,0);
         int n = bills.size();

         for(int i = 0; i < n; i++){
            if(bills[i] == 5) account[0]++;

            else if(bills[i] == 10){
                if(account[0] == 0) return false;
                account[0] --;

                account[1]++;
            }

            else {
                if(account[0] > 0 && account[1] > 0){
                    account[0]--;
                    account[1]--;
                }
                else if(account[0] > 2) account[0] -= 3;
                else return false;

                account[2]++;
            }
         }

         return true;
    }
};