class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size(), high = n-1, low = 0, boats = 0;
        sort(people.begin(), people.end());
        while(low < high){
            if(people[high] == limit){ // weight limit reached by including the person at high
                high--;
                boats++;
            }
            if(people[low] == limit){ // weight limit reached by including the person at low
                low++;
                boats++;
            }
            if(people[low]+people[high] <= limit){// can include at max two persons with combined weight- limit
                high--; low++;
                boats++;
            }
            else{ // combined weight exceeds the limit can include any one greedly take the bigger weighted person
                high--;
                boats++;
            }
        }
        if(low == high){
            return boats+1; // +1 for the person at index i (or j)
        }
        return boats;
    }
};