class Solution {
public:
    // bills[i] == 5 => need to return 0
    // bills[i] == 10 => need to return 5, must have 5 in pocket
    // billa[i] == 20 => need to return 15, either need one 10 and one 5 or three 5s
    bool lemonadeChange(vector<int>& bills) {
        int fiveCount = 0, tenCount = 0, twentyCount = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5) fiveCount++;
            if(bills[i] == 10){
                tenCount++;
                if(fiveCount <= 0) return false;
                fiveCount--;
            }
            else if(bills[i] == 20){
                twentyCount++;
                if(tenCount >= 1 && fiveCount >= 1){
                    tenCount--; fiveCount--;
                }
                else if(fiveCount >= 3){
                    fiveCount -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};