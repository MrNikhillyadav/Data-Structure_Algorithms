class Solution {
public:
    //Pattern : Heap + Cycles
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for(char ch : tasks){
            freq[ch - 'A']++;
        }

        priority_queue<int> maxHeap;

        for(int f : freq){
            if(f > 0) maxHeap.push(f);
        }

        int time = 0;

        while(!maxHeap.empty()){
            int cycle = n + 1;
            vector<int> temp;

            while(cycle-- && !maxHeap.empty()){
                int f = maxHeap.top(); maxHeap.pop();
                f--;

                if(f > 0) temp.push_back(f);

                time++;
            }

            for(int f : temp){
                maxHeap.push(f);
            }

            // if heap still has elements → idle time needed
            if(!maxHeap.empty()){
                time += cycle + 1;
            }
        }

        return time;
    }
};// Time Complexity : ~O(n) (maxHeap's log 26 is constant)

/*
    Pattern : Heap + Cycles

        - We process tasks in cycles of size (n + 1), means :
        - Each cycle, Pick up to (n + 1) most frequent tasks to avoid repeating same task too early.
        
    Golden Mental Note
        If constraint is "no adjacent" → pick 2   ( e.g. Reorganize string).
        If constraint is "distance k" → pick k+1 

    “How did you approach this?”
        - I process tasks in cycles of size n+1, always picking the most frequent tasks to minimize idle time.

    Mental Model (VERY IMPORTANT)

        Reorganize String
            Constraint: distance = 1
            → pick 2 at a time
            
        Task Scheduler
            Constraint: distance = n
            → pick n+1 at a time
*/
