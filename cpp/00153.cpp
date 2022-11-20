// Next half intuition:
// [2,3,4,5,1] - right - bounds decrease - mid > left && mid > right
// [1,2,3,4,5] - left - bounds increase - mid > left && mid < right
// [5,1,2,3,4] - left - bounds decrease - mid < left && mid < right
class Solution {
public:
    // More concise - return outside
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high])
                low = mid + 1;
            else high = mid;
        }
        return nums[low];
    }
    
    // Original solution - return in loop
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((high - low + 1) % 2 == 0) mid++;
            
            if (mid == 0 || nums[mid - 1] > nums[mid])
                return nums[mid];
            
            if (nums[mid] > nums[high])
                low = mid;
            else high = mid - 1;
        }
        return -1;
    }
};
