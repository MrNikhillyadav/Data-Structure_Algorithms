class Solution {
public:
    void generate(int open, int close,int n, string &temp, vector<string> &res){
        if(open == n && close == n){
            res.push_back(temp);
            return;
        }

        if(open < n){
            temp.push_back('(');
            generate(open+1, close, n, temp, res);
            temp.pop_back();
        }

        if(close < open){
            temp.push_back(')');
            generate(open, close+1, n, temp, res);
            temp.pop_back();
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp = "";

        generate(0,0,n,temp,res);

        return res;
    }
};

/*
    Mental Model

        Think like:

           - I am building ONE string step by step
           - When it's valid → store it
           - Then undo and try another path

        #Backtracking Pattern
           - make choice
           - recurse
           - undo choice
*/