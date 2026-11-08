/*
f % 3 == 0: all 3s, so rounds = f / 3. Easy.
f % 3 == 2: use as many 3s as possible, then the leftover 2 is one extra round of size 2. Check with f = 8: 3 + 3 + 2 → 3 rounds, and 8/3 = 2, so rounds = f/3 + 1.
f % 3 == 1: this is the tricky one. If you take as many 3s as possible, you’re left with a 1, which can’t be a round. So you must “give back” one 3 and turn 3 + 1 = 4 into 2 + 2. Check f = 7: 3 + 2 + 2 → 3 rounds, and 7/3 = 2, so rounds = f/3 + 1.
// (rounds == opearions)
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(const auto& n: nums){
            freq[n]++;
        }
        for(const auto& [n, f]: freq){
            if(f == 1) return -1;
        }
        int operations = 0;
        for(const auto& [n, f]: freq){
            if(f % 3 == 0){
                operations += f/3;
            }
            else{
                operations += (f/3)+1;
            }
        }
        return operations;
    }
};