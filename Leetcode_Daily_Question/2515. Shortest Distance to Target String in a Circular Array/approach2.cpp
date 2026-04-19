class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        //Approach 2 (Better)
        int n = words.size();
        int ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                int dist = abs(i - startIndex);
                int circularDist = n - dist;
                ans = min(ans, min(dist, circularDist));
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};

/*  
    Intuition You Should Remember: 
        Circular array → distance is not just |i - j| → also consider Wrap-around distance = n - |i - startIndex|

    Why this works?

        In a circular array:
            - Direct distance = |i - startIndex|
            - Wrap-around distance = n - |i - startIndex|

        Take minimum of both.

    We don’t need to simulate movement like in Approach 1.
*/