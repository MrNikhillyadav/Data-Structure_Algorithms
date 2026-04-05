class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int left = 0;
        int right = people.size()-1;
        int boats = 0;

        while(left <= right){
            if(people[left] + people[right] <= limit ){
                left++;
            }
            right--;
            boats++;
        }
        return boats;
    }
};

/* Greedy Approach (Two Pointer)
Best strategy:
    Pair lightest + heaviest

    Why?
        - Heaviest person is hardest to place
        - Try to fit them with smallest possible partner
*/