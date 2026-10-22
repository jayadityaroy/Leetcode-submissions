class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int,int>>timelines;
        for(int i = 0; i < n; i++){
            timelines.push_back({intervals[i][0], +1});
            timelines.push_back({intervals[i][1], -1});
        }
        sort(timelines.begin(), timelines.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if(a.first != b.first) return a.first < b.first;
            else return a.second > b.second;
        });
        int groupCount = 0, sum = 0;
        for(int i = 0; i < timelines.size(); i++){
            sum += timelines[i].second;
            groupCount = max(groupCount, sum);
        }
        return groupCount;
    }
};