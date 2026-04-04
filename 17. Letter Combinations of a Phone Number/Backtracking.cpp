class Solution {
public:
    void generateCombinations(string digits, int n, int idx, string &temp, vector<string> &res){
        unordered_map<char,string> f;

        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        // base case
        if( idx == n){
            // store temp in res
            res.push_back(temp);
            return;
        }

        //choices
        string choices = f[digits[idx]];  // 2 --> "abc"

        // iterate over each letter
        for(int i = 0; i < choices.size(); i++){
            temp.push_back(choices[i]);
            generateCombinations(digits, n, idx + 1, temp, res);
            temp.pop_back();
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
       
        int n = digits.size();
        string temp = "";
        vector<string> res; 
        int idx = 0;

        generateCombinations(digits, n, idx, temp, res );
        
        return res;
    }
};

/*
    Pattern Recognition
        - This is NOT pick/not-pick.
        - This is:
            “For each digit → try ALL possible letters”

    Template for This Type
        for(each choice at current index):
            - pick choice
            - recurse to next index
            - undo

    Final Insight
        Recursion = moving index
        Backtracking = trying all choices at that index
*/