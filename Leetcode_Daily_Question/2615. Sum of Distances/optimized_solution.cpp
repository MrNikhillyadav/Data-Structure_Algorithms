class Solution {
public:
// 
    void check(vector<int>& nums, vector<long long>& res){
        unordered_map<int,vector<int>> mp;

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        
        //process each group
        for(auto &it : mp) {
            vector<int>& indices = it.second;
            int k = indices.size();

            vector<long long> prefix(k);
            prefix[0] = indices[0];

            for(int i = 1; i < k; i++) {
                prefix[i] = prefix[i-1] + indices[i];
            }

            // iterating over prefixSum vector
            for(int i = 0; i < k; i++) {
                long long left = 0, right = 0;

                if(i > 0) {
                    left = (long long)i * indices[i] - prefix[i-1];
                }

                if(i < k - 1) {
                    right = (prefix[k-1] - prefix[i]) - (long long)(k - i - 1) * indices[i];
                }

                res[indices[i]] = left + right;
            }
        }
    }

    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long>  res(n,0);
        check(nums, res);

        return res;
    }
};

/*
    Time:  O(n), Space: O(n)

    Pattern for :
        "Sum of distances in array" → use prefix sum + grouping

    Memory Hook
        "distance sum = left cost + right cost"

    Final Formula

        For index at position p:
            left  = p * indices[p] - prefix[p-1]
            right = (prefix[last] - prefix[p]) - (k - p - 1) * indices[p]

        Total: 
            ans[p] = left + right

*/