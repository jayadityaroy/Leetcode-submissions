class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>sortedLogs;
        for(const auto& l: logs){
            sortedLogs[l[0]]++;
            sortedLogs[l[1]]--;
        }
        for(const auto& [year, res]: sortedLogs){
            cout<<year<<": "<<res<<endl;
        }
        int total = 0, maxi = INT_MIN, year;
        for(const auto& l: sortedLogs){
            if(total + l.second > maxi){
                year = l.first;
                maxi = total + l.second;
            }
            total = total + l.second;
        }
        return year;
    }
};