class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> result;
        int ptr1 = 0, ptr2 = 0;

        while (ptr1 != m && ptr2 != n)
            result.push_back(
                nums1[ptr1] < nums2[ptr2] ? nums1[ptr1++] : nums2[ptr2++]
            );

        for (int i = ptr1; i != m; i++)
            result.push_back(nums1[i]);

        for (int i = ptr2; i != n; i++)
            result.push_back(nums2[i]);

        for (int i = 0; i != reult.size(); i++)
            nums1[i] = result[i];
    }
};

