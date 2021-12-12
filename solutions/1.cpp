class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        
        for (int i = 0; i != nums.size(); i++) {
            if (map.find(target - nums[i]) != map.end())
                return vector<int>({i, map[target - nums[i]]});
            
            map[nums[i]] = i;
        }
        
        return vector<int>();
    }
};

