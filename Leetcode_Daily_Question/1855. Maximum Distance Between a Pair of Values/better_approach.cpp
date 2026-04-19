class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = INT_MIN;
        int m = nums1.size();
        int n = nums2.size();

        int i=0; 
        int j=0;

        while( i < m && j < n ){
            if( nums1[i] <= nums2[j]){
                int dis = j-i;
                res = max(res, dis);
                j++;
                continue;
            }
            i++;
            j++;
        }

        return (res == INT_MIN)? 0 : res;
    }
};