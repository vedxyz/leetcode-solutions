class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int> heap;
        vector<int> seq = nums;
        
        for (int i = 0; i != nums.size(); i++) {
            heap.push(nums[i]);
            if (heap.size() > nums.size() - k)
                heap.pop();
        }
        
        while (!heap.empty()) {
            seq.erase(find(seq.begin(), seq.end(), heap.top()));
            heap.pop();
        }
        
        return seq;
    }
};

