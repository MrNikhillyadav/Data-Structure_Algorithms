class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;

        // Step 1: frequency map
        for(char c : s){
            mp[c]++;
        }

        // Step 2: max heap {freq, char}
        priority_queue<pair<int,char>> maxHeap;

        for(auto &it : mp){
            maxHeap.push({it.second, it.first});
        }

        string res = "";

        // Step 3: process two at a time
        while(maxHeap.size() > 1){
            auto [freq1, ch1] = maxHeap.top(); maxHeap.pop();
            auto [freq2, ch2] = maxHeap.top(); maxHeap.pop();

            res += ch1;
            res += ch2;

            freq1--;
            freq2--;

            if(freq1 > 0) maxHeap.push({freq1, ch1});
            if(freq2 > 0) maxHeap.push({freq2, ch2});
        }

        // Step 4: handle last character
        if(!maxHeap.empty()){
            auto [freq, ch] = maxHeap.top();

            if(freq > 1) return ""; // not possible
            res += ch;
        }

        return res;
    }
};// Visualize like pratyush : Student seating arrangement in examps for Class X and Class XII.

/*
    Better Approach (Greedy + Max Heap)
    Idea:
        Pick top 2 most frequent characters (as No two adjacent characters should be same)
        Add both to result
        Reduce frequency
        Push back if still remaining

    Time Complexity : O(n) + O(k log k) + O(n log k) -----> O(n log k);
    Space Complexity : O(k) + O(k) -----> O(n);


    Optimized Approach (Even Better)

        Use:
        - array[26] instead of heap
*/