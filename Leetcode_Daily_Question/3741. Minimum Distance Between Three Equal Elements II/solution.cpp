class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        // Step 1: store indices for each value
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = INT_MAX;

        // Step 2: process each value group
        for(auto &it : mp) {
            vector<int> &indices = it.second;

            // need at least 3 occurrences
            if(indices.size() < 3) continue;

            // Step 3: sliding window of size 3
            for(int i = 0; i + 2 < indices.size(); i++) {
                int dist = 2 * (indices[i+2] - indices[i]);
                ans = min(ans, dist);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};//o(n)

/*
    Core Pattern
        - Group by value → work on indices → sliding window of size 3

    Key Mathematical Insight
        If you assume:
            i < j < k
            Then:
                |i - j| = (j - i)
                |j - k| = (k - j)
                |k - i| = (k - i)

                So total becomes:

                (j - i) + (k - j) + (k - i)
                = k - i + k - i
                = 2 * (k - i)

        Distance depends ONLY on the first and last index. Middle index doesn’t matter much.
        👉 distance = 2 * (k - i)

    Final Pattern Locked In
        - “Whenever you need min/max distance among same elements → store indices → use sliding window”          
*/