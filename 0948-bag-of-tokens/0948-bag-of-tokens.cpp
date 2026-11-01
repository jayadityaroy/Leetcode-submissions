// Greedy Approach: Buy tokens with small values, Sell tokens with large values to increase power!
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int low = 0, high = n-1;
        int score = 0;
        while(low < high){
            if(power >= tokens[low]){
                score++;
                power = power - tokens[low];
                low++;
            }
            else{
                if(score-1 < 0) return score;
                score--;
                power = power + tokens[high];
                high--;
            }
            cout<<power<<", ";
        }
        if(low == high && power >= tokens[low]){
            score++;
        }
        return score;
    }
};