// new answer interval approach:
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ansIntervals;
        int i = 0;
        while(i < intervals.size()){
            if(intervals[i][1] < newInterval[0]){
                ansIntervals.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1]){
                break;
            }
            else{ //merge
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
            i++;
        }
        ansIntervals.push_back(newInterval);
        while(i < intervals.size()){
            ansIntervals.push_back(intervals[i]);
            i++;
        }
        return ansIntervals;
    }
};