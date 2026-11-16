class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int candies = n;
        // find the peaks:
        vector<pair<int,int>> peaks; // peaks[i] == {rating, index}
        for(int i = 0;i < n; i++){
            if((i-1 >= 0 && ratings[i-1] < ratings[i])||(i+1 < n && ratings[i+1] < ratings[i])){
                peaks.push_back({ratings[i], i});
            }
        }
        // sort the peaks according to the ratings:
        sort(peaks.begin(), peaks.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });

        // candy allocation
        vector<int>candy(n, 1);
        for(int i = 0; i < peaks.size(); i++){
            int ind = peaks[i].second;
            int rate = peaks[i].first;
            int extraCandies = 0;
            if(ind - 1 >= 0 && ratings[ind-1] < rate){
                extraCandies = candy[ind-1];
            }
            if(ind+1 < n && ratings[ind+1] < rate){
                extraCandies = max(extraCandies, candy[ind+1]);
            }
            candy[ind] += extraCandies;
            candies += extraCandies;
        }
        
        return candies;
    }
};