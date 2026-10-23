// optimised approach:
/*
Since a cut’s cost doesn’t depend on where it is, the order of cuts is the same in every piece: largest cost first.
So you repeat the same decisions in thousands of sub-rectangles, and that repetition is what you can skip.
*/
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<pair<int,int>> cuts; // cuts[i] = {cuts score, 1/0} // 1 for h and 0 for v
        for(int i = 0; i < m-1; i++){
            cuts.push_back({horizontalCut[i], 1});
        }
        for(int i = 0; i < n-1; i++){
            cuts.push_back({verticalCut[i], 0});
        }
        sort(cuts.begin(), cuts.end());

        int hPieces = 1, vPieces = 1;
        long long score = 0;
        for(int i = cuts.size()-1; i >= 0; i--){
            if(cuts[i].second == 1){
                score += cuts[i].first * vPieces;
                hPieces++;
            }
            else{
                score += cuts[i].first * hPieces;
                vPieces++;
            }
        }
        return score;
        
    }
};