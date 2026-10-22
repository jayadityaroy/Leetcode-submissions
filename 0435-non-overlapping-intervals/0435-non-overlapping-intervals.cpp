// Optimised approach:
/*
When two intervals overlap, you must remove one of them. Which one you keep matters.
Keep the one that ends earlier, because it leaves more room for future intervals.
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int removeCount = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] != b[0]) return a[0] < b[0];
            else return a[1] < b[1];
        });
        int prevS = intervals[0][0], prevE = intervals[0][1];
        for(int i = 1; i < n; i++){
            int currS = intervals[i][0], currE = intervals[i][1];
            if((currS < prevE)){ // overlap
                removeCount++;
                prevE = min(prevE, currE); // keep the shorter interval
                continue;
            }
            prevS = currS, prevE = currE; // update when non overlapping interval found
        }
        return removeCount;
    }
};