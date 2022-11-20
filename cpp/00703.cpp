class KthLargest {
    priority_queue<int, vector<int>, greater<int>> heap;
    int k;
    
    void push_heap(int val) {
        heap.push(val);
        if (heap.size() > k)
            heap.pop();
    }
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for (int i = 0; i != nums.size(); i++)
            push_heap(nums[i]);
    }
    
    int add(int val) {
        push_heap(val);
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

