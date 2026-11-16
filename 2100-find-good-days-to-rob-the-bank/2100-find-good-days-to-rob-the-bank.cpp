class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> desc(n, 0); // number of consecutive decreasing days ending at index i
        vector<int> aesc(n, 0); // number of consecutive increasing days startig att index i
        for(int i = 1; i < n; i++){
            if(security[i-1] >= security[i]){
                desc[i] = 1 + desc[i-1];
            }
        }
        for(int i = n-2; i >= 0; i--){
            if(security[i] <= security[i+1]){
                aesc[i] = 1 + aesc[i+1];
            }
        }

        vector<int> goodDays;
        for(int i = time; i < n-time; i++){
            if(desc[i] >= time && aesc[i] >= time){
                goodDays.push_back(i);
            }
        }
        return goodDays;
    }
};