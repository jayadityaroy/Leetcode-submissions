/*
f % 3 == 0: all 3s, so rounds = f / 3. Easy.
f % 3 == 2: use as many 3s as possible, then the leftover 2 is one extra round of size 2. Check with f = 8: 3 + 3 + 2 → 3 rounds, and 8/3 = 2, so rounds = f/3 + 1.
f % 3 == 1: this is the tricky one. If you take as many 3s as possible, you’re left with a 1, which can’t be a round. So you must “give back” one 3 and turn 3 + 1 = 4 into 2 + 2. Check f = 7: 3 + 2 + 2 → 3 rounds, and 7/3 = 2, so rounds = f/3 + 1.
*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        unordered_map<int,int> freq;
        for(int i = 0; i < n; i++){
            freq[tasks[i]]++;
        }
        for(auto [task, f]: freq){
            if(f == 1) return -1; //not possible to complete this task
        }
        int rounds = 0;
        for(const auto& [task, f]: freq){
            if(f % 3 == 0){
                rounds += f/3;
            }
            else{
                rounds += (f/3)+1;
            }
        }
        return rounds;
    }
};