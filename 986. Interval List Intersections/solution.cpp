class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        vector<vector<int>> res;

        int m = firstList.size();
        int n = secondList.size();

        int i = 0;
        int j = 0;

        while(i < m && j < n){

            int start1 = firstList[i][0];
            int end1   = firstList[i][1];

            int start2 = secondList[j][0];
            int end2   = secondList[j][1];

            int start = max(start1,start2);
            int end   = min(end1,end2);

            if(start <= end){ // intersection interval
                res.push_back({start,end});
            }

            if(end1 < end2){
                i++;
            }
            else{
                j++;
            }
        }

        return res;
    }
};

/* 
    Mental Model

    Every iteration:
        intersection_start = max(start1,start2)
        intersection_end   = min(end1,end2)

    If
        start <= end

    then intervals intersect.
*/