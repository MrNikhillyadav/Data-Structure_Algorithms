class Solution {
public:
// Optimal Approach : Binary Search
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int n = nums2.size();

        for(int i = 0; i < nums1.size(); i++) {
            int left = i, right = n - 1;
            int best = -1;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                if(nums2[mid] >= nums1[i]) {
                    best = mid;      
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if(best != -1) {
                res = max(res, best - i);
            }
        }

        return res;
    }
};
//Time Complexity = O(n log m)

/*
    Pattern Recognition
        If you see:
            "For each i, find farthest j"
            Think :
                - Binary search on j

    Intuition Breakdown
        For each i:
          - We want FARTHER j (maximize j - i)

    Interview Gold Line
            “If we need per-index optimal j, I’ll use binary search instead of two pointers.”

    Key Insight:
        Two pointers → when global monotonicity exists  
        Binary search → when each index needs independent answer
*/