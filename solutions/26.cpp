class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        
        for (int i = 0; i != nums.size(); i++)
            if (nums[idx] != nums[i])
                nums[++idx] = nums[i];
        
        return nums.empty() ? 0 : idx + 1;
    }
};

