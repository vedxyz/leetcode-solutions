class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;
        for (int i = 0; i != nums.size(); i++) {
            single ^= nums[i];
        }
        return single;
    }
};

