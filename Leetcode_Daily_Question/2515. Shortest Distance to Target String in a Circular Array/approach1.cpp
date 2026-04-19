class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
    // Method 1: Two-direction simulation.

        int n = words.size();

        for(int step = 0; step < n; step++) {
            int forward = (startIndex + step) % n;
            int backward = (startIndex - step + n) % n;

            if(words[forward] == target || words[backward] == target) {
                return step;
            }
        }

        return -1;
    }
};

/*
    Mental Model 
        Circular movement problems →

        Either:
            Method 1. Simulate step-by-step
            OR
            Method 2. Convert to math distance (better)
*/