// Brute force approach:
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> diff(n); // diff[i] == capacity[i] - rocks[i]
        int fullCapCount = 0; // count of bags at full capacity
        for(int i = 0; i < n; i++){
            diff[i] = capacity[i]-rocks[i];
            if(diff[i] == 0) fullCapCount++;
        }
        sort(diff.begin(), diff.end());
        for(int i = 0; i < n; i++){
            if(diff[i] == 0)continue;
            else{
                if(additionalRocks >= diff[i]){
                    additionalRocks -= diff[i];
                    fullCapCount++;
                }
                else break;
            }
        }
        return fullCapCount;

    }
};