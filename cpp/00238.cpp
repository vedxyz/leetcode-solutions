class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size(), 1);
        
        for (int i = 1; i != nums.size(); i++)
            products[i] = products[i - 1] * nums[i - 1];
        
        int rProduct = 1;
        for (int i = nums.size() - 1 - 1; i >= 0; i--)
            products[i] *= rProduct *= nums[i + 1];
        
        return products;
    }
};
