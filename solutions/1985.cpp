struct CompareStr {
    bool operator()(string& a, string& b) {
        if (a.size() != b.size()) return a.size() > b.size();
        return a > b;
    }
};
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, CompareStr> heap;
        
        for (int i = 0; i != nums.size(); i++) {
            heap.push(nums[i]);
            if (heap.size() > k)
                heap.pop();
        }
        
        return heap.top();
    }
};

