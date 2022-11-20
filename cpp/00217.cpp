class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ints;
        
        for (int i = 0; i != nums.size(); i++) {
            if (ints.find(nums[i]) != ints.end())
                return true;
            
            ints.insert(nums[i]);
        }
        
        return false;
    }
};

