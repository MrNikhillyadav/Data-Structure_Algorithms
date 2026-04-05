class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();

        if(n == 1){
            return "";
        }

        for(int i=0; i < n/2; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        // all characters in first half are 'a'
        palindrome[n-1] = 'b';

        return palindrome;
    }
};

/*
    Greedy Approach:

    ✔ Check first half
    ✔ Replace first non-'a' with 'a'
    ✔ Else modify last character

    Why < n/2 and not <= ?
        Middle character doesn’t affect palindrome.

    

*/