class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int prevMax = 0;
        int time = 0;

        for(int i=0; i<n; i++){

            if(i > 0 && colors[i] != colors[i-1]){ // not same colors
                prevMax = 0;
            }

            int curr = neededTime[i];
       
            time += min(prevMax,curr);   // greedily, we are picking min
            prevMax = max(prevMax,curr);
        }
        return time;
    }
};

/*  Pattern Name : Group-based Greedy / Local Conflict Resolution
        - “In a conflict group, always keep the strongest and eliminate the weaker ones.”

    Mental Model:
       -  “Whenever I see duplicates, I must delete all except one — so keep the most expensive, delete the rest.”
    
*/