class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        // min heap by capital
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minCapital; 

        int n = profits.size();

        // max heap by profit
        priority_queue<int> maxProfit;

        // Step 1: store projects
        for(int i = 0; i < n; i++){
            minCapital.push({capital[i], profits[i]});
        }

        // Step 2: do k projects
        for(int i = 0; i < k; i++){

            // add all feasible projects
            while(!minCapital.empty() && minCapital.top().first <= w){
                maxProfit.push(minCapital.top().second);
                minCapital.pop();
            }

            // if no feasible project
            if(maxProfit.empty()) break;

            // pick best profit
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
}; // TC : O(n log n)

/*
    Pattern : Greedy + Two Heaps 

        Min Heap (capital)  →    find feasible projects
        Max Heap (profit)	→    pick best project

    “At each step, I push all feasible projects into a max heap and pick the most profitable one.”

    Idea:
    - Store all projects sorted by capital required
    - Push all feasible projects into a max heap (by profit)
    - Pick the most profitable one
    - Increase capital
    - Repeat k times
*/