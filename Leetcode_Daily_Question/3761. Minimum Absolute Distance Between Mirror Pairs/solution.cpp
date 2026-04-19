class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> lastSeen; // maps reversed value -> last index stored
        int minDist = INT_MAX;

        for (int j = 0; j < (int)nums.size(); j++) {
            int rev = reverseNum(nums[j]);

            // Check if current number was stored as a reverse of some earlier number
            if (lastSeen.count(nums[j])) {
                minDist = min(minDist, j - lastSeen[nums[j]]);
            }

            // Store the reversed value of nums[j] -> j
            lastSeen[rev] = j;
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};

/*  
    Core Idea (1-liner)
        Instead of searching for reverse, store reverse → match original

    Visual Mental Model :
        nums = [21, 12]
        
        Step 1:
        21 → store reverse(21)=12

        Step 2:
        12 → check → yes 12 exists → match found

    Memory Hook (super sticky)
        "Don’t search for reverse — store reverse and wait"
*/
