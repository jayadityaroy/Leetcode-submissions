// Help from neetcode
// using Max heap
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // STEP 1: Count frequency of each task
        // We only care about how many of each task we have, not the actual characters
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        // STEP 2: Priority Queue (Max-Heap) stores the frequencies
        // This ensures we always process the task with the most remaining work first (Greedy)
        priority_queue<int> maxHeap;
        for (auto& entry : freq) {
            maxHeap.push(entry.second);
        }

        int time = 0;
        
        // STEP 3: Deque acts as a "Waiting/Cooling Room"
        // It stores {remaining_frequency, time_when_available_again}
        deque<pair<int,int>> dq; 

        while (!maxHeap.empty() || !dq.empty()) {
            time++; // Each iteration represents one unit of CPU time
            
            // IF HEAP IS NOT EMPTY: We have a task available to run
            if(!maxHeap.empty()) {
                int freqLeft = maxHeap.top() - 1; // Run task once, decrement count
                maxHeap.pop();
                
                // If the task still has work left, it must go to the cooling room
                // It cannot be run again until 'time + n'
                if(freqLeft > 0) {
                    dq.push_back({freqLeft, time + n});
                }
            }

            // IF DEQUE IS NOT EMPTY: Check if any task has finished its cooling period
            // We check the front because the deque is naturally sorted by time
            if(!dq.empty() && time == dq.front().second) { 
                // Cooling period is over! Move it back to the available heap
                maxHeap.push(dq.front().first);
                dq.pop_front();
            }
        }
        
        return time;
    }
};