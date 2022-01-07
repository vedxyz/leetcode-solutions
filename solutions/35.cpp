class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums[0] > target) return 0;
        
        int low = 0, high = nums.size();
        while (low != high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] <= target && (mid + 1 == nums.size() || target < nums[mid + 1]))
                return nums[mid] == target ? mid : mid + 1;
            
            if (nums[mid] < target)
                low = mid + 1;
            else high = mid;
        }
        return -1;
    }
};
