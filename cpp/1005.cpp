class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int sum = 0;
        priority_queue<int, vector<int>, greater<int>> heap(nums.begin(), nums.end());
        
        while (k--) {
            int minint = heap.top();
            heap.pop();
            heap.push(-minint);
        }
        
        while (!heap.empty()) {
            sum += heap.top();
            heap.pop();
        }
        
        return sum;
    }
};

