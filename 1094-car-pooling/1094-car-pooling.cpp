// Line sweep technique:
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp; // mp[time] = passengers picked / dropped
        for(int i = 0; i < trips.size(); i++){
            int passengers = trips[i][0], start = trips[i][1], end = trips[i][2];
            // passengers picked at start
            mp[start] += passengers;
            // passengers dropped at 
            mp[end] -= passengers;
        }
        int totPassengers = 0; // maximum passengers at any point of time
        for(const auto& m: mp){
            totPassengers += m.second;
            if(totPassengers > capacity){
                return false; // totPassengers exceeds total capacity
            }
        }
        return true;
    }
};