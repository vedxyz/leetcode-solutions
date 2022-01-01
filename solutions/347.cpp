class Solution {
    struct Freq {
        int val;
        int count;
        bool operator()(const Freq& a, const Freq& b) {
            return a.count > b.count;
        }
    };
    typedef unordered_map<int, Freq> freqmap;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        freqmap freq;
        for (int i = 0; i != nums.size(); i++) {
            if (!freq.count(nums[i])) {
                freq[nums[i]].val = nums[i];
                freq[nums[i]].count = 0;
            }
            freq[nums[i]].count++;
        }
        
        priority_queue<Freq, vector<Freq>, Freq> heap;
        for (freqmap::iterator i = freq.begin(); i != freq.end(); i++) {
            heap.push(i->second);
            if (heap.size() > k)
                heap.pop();
        }
        
        vector<int> topfreq;
        while (!heap.empty()) {
            topfreq.push_back(heap.top().val);
            heap.pop();
        }
        
        return topfreq;
    }
};

