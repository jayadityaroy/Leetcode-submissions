// Approach:
// minimum moves >= maximum flow at any point (flow of clothes of L to R or R to L)
// minimum moves >= maximum extra clothes present in any machine
// minimum moves >= max(maxi flow, maxi extra)
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        int totClothes = 0;
        for(int i = 0; i < n; i++){
            totClothes += machines[i];
        }   
        if(totClothes % n != 0) return -1;
        int target = totClothes/n; 
        // flow at each point:
        vector<int> flow(n); // flow[i] => incoming(-)/outgoing(+) number of clothes from [0, i] to [i+1, n-1]
        vector<int> balance(n); // balance[i] => amount of clothes need(-) or can give(+) to others
        int maxiFlow = -1e9; // maximum possible flow
        int maxiExtra = -1e9; // maximum extra clothes in any machine
        balance[0] = machines[0]-target;
        flow[0] = balance[0];
        maxiFlow = flow[0];
        for(int i = 1; i < n; i++){
            balance[i] = machines[i]-target;
            maxiExtra = max(maxiExtra, (balance[i]));
            flow[i] = flow[i-1] + balance[i];
            maxiFlow = max(maxiFlow, abs(flow[i]));
        }
        // mini moves
        return max(maxiFlow, maxiExtra);
    }
};