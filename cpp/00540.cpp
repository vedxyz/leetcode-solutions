class Solution {
    bool isNonDuplicate(vector<int>& nums, int i) {
        if (nums.size() == 1) return true;
        return (i == 0 || nums[i - 1] != nums[i]) && 
            (i + 1 == nums.size() || nums[i] != nums[i + 1]);
    }
public:
    int singleNonDuplicate(vector<int>& nums) {
        // size is always odd
        // middle element is either nonduplicate or
        // if ((high-low+1) / 2) % 2
            // aazbbcc - x.a.a - left - low, mid - 1
            // aabbzcc - a.a.x - right - mid + 1, high
        // if ((high-low+1) / 2) % 2 == 0
            // aazbbccdd - a.a.x - left - low, mid - 2
            // aabbcczdd - x.a.a - right - mid + 2, high
        int low = 0, high = nums.size() - 1;
        while (!isNonDuplicate(nums, low + (high - low) / 2)) {
            int mid = low + (high - low) / 2;
            if (((high - low + 1) / 2) % 2) {
                if (nums[mid] == nums[mid + 1])
                    high = mid - 1;
                else low = mid + 1;
            } else {
                if (nums[mid] == nums[mid + 1])
                    low = mid + 2;
                else high = mid - 2;
            }
        }
        
        return nums[(high + low) / 2];
    }
};

