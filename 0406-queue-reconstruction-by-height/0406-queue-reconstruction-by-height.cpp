// Approach:
// shortest first + “k-th empty slot”. Shorter people are processed first, and the empty slots left over will be filled by taller-or-equal people later. So a person with k goes into the slot that has exactly k empty slots before it
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n= people.size();
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<vector<int>>ans(n, vector<int>(2, -1));
        for(int i = 0; i < n; i++){
            int frontPpl = people[i][1]; // count of people front of peopel[i][1]
            for(int j = 0; j < n; j++){
                if(frontPpl == 0 && ans[j][0] == -1){ // found the correct position
                    ans[j] = people[i];
                    break;
                }
                else if(ans[j][0] >= people[i][0] || ans[j][0] == -1){ // skip the current position for someone with bigger or same height or is already filled by someone with same height or bigger height
                    frontPpl--;
                }
            }
        }
        return ans;
    }
};