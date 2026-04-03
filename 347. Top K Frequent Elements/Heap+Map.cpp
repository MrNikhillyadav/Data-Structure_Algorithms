class Solution {
public:
    struct cmp {
        bool operator()(pair<int,int> &a, pair<int,int> &b){
            return a.first > b.first; // min heap by frequency
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> minHeap; //min_heap storing {frequency, number}
        unordered_map<int,int> mp;
        vector<int> res;

        for(auto num : nums){
            mp[num]++;
        }

        for(auto x : mp){
            minHeap.push({x.second, x.first}); //heap stores {frequency, number}

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

       while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
       }

        return res;
    }
};

/*
    optimized way (Map + Heap):

        Map → gives frequency
        Heap → filters top K

        - 1. using a Hashmap to store {element -> freq}
        - 2. now, maintain a minHeap of size K 

        TC : NLogK

*/