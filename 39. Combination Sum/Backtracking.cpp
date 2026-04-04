class Solution {
public:
    void generate(vector<int>& candidates, int target, int sum, vector<int>& temp, vector<vector<int>>& res, int idx) {
        
        // base case
        if(sum == target){
            res.push_back(temp);
            return;
        }

        // out of bounds or overflow
        if(idx >= candidates.size() || sum > target) return;

        // pick (same index → reuse allowed)
        temp.push_back(candidates[idx]);
        generate(candidates, target, sum + candidates[idx], temp, res, idx);
        temp.pop_back();

        // not pick (move forward)
        generate(candidates, target, sum, temp, res, idx + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        generate(candidates, target, 0, temp, res, 0);
        return res;
    }
};

/*
    Pattern Type : Backtracking [pick multiple times]

    Mental Model (THIS WILL STICK)
        - You are filling a bag with numbers
        - You can reuse same item unlimited times
        - Move forward only when you decide to skip it
*/