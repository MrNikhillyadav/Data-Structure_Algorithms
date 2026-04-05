class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end()); // nlogn;

        int left = 0;
        int right = tokens.size() -1;
        int res = 0;
        int score = 0;

        while(left <= right){
                // score = 0, play face-up --> power reduces, score increase.
            if(tokens[left] <= power){
                power -= tokens[left];
                score += 1;
                res = max(res,score);
                left++;
            }
            else if(score > 0 ){
                //score > 0; play face-down ----> power increase, socre decreases.
                power += tokens[right];
                score -= 1;
                res = max(res,score);
                right--;
            }else{
                break;
            }

        }
        return res;
    }
};

/*  Pattern : Greey + Two pointers

    Mental Model
    - Use smallest tokens to build score  
    - Use largest tokens to recover power

    Interview Answer (Very Strong)

    If interviewer asks:

        “Can we use two heaps?”
        You say:
        --> “We can, but it introduces synchronization issues because removing an element from one heap requires removing it from the other, which is inefficient. Using sorting with two pointers avoids this and is cleaner.”

    Final Mental Model
        Heap → one-sided decisions  
        Two pointers → two-sided decisions
*/
