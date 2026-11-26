class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
      map<int,bool> mp;
      for(const auto& n: nums){
        int start = n[0], end = n[1];
        for(int i = start; i <= end; i++){
            mp[i] = true;
        }
      }  
      return mp.size();
    }
};