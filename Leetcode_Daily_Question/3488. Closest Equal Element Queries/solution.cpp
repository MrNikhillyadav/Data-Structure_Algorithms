class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;

        // store indices
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res;

        for(int q : queries) {
            int val = nums[q];
            vector<int>& indices = mp[val];

            if(indices.size() == 1) {
                res.push_back(-1);
                continue;
            }

            int ans = INT_MAX;

            // find position of q using Binary Search
            auto it = lower_bound(indices.begin(), indices.end(), q);
            int pos = it - indices.begin();

            // next index (circular)
            int next = indices[(pos + 1) % indices.size()];
            int d1 = abs(next - q);
            ans = min(ans, min(d1, n - d1));

            // previous index (circular)
            int prev = indices[(pos - 1 + indices.size()) % indices.size()];
            int d2 = abs(prev - q);
            ans = min(ans, min(d2, n - d2));

            res.push_back(ans);
        }

        return res;
    }
};

/*
    Final Derived Algorithm
        Preprocess → O(n)

        For each query:
            → binary search → O(log n)
            → check 2 neighbors → O(1)

        Total → O(n + m log n)

    If interviewer asks, say:

        “Brute force would be O(n*m), but we are repeating work.
        Since queries depend on values, I’ll group indices by value.
        Then for each query, I’ll binary search to find nearest occurrence.
        Since indices are sorted, closest must be adjacent elements.
        I’ll check left and right neighbors and compute circular distance.”

    Final Mental Framework
        Repeated queries + same values
        → group indices

        Sorted data + closest element
        → binary search + neighbors

        Circular structure
        → min(d, n-d)

    Memory Hook
        "group → search → neighbors → circular distance"
*/