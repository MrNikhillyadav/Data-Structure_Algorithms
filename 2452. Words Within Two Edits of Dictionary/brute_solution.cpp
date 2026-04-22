class Solution {
public:
// Optimized Brute Approach :
    bool isValid(string &a, string &b){
        int diff = 0;
        for(int i=0; i<a.size(); i++){
            if(a[i] != b[i]){
                diff++;
                if(diff > 2){      // pruning
                    return false;
                }
            }
        }
        return true;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;

        for(auto q : queries){
            for(auto d : dictionary){
                if(isValid(q,d)){
                    result.push_back(q);
                    break;
                }
            }
        }
        return result;
    }
};// TC :  O(Q × D × L)

/*
    1. We have modeled this as a Hamming distance ≤ 2 problem.   
        This brute force solution is O(Q × D × L), but we can optimize using pattern hashing.

    2. Hamming Distance = number of positions where two strings differ
        Condition: Both strings must be of same length
*/