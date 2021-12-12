class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int ptr1 = 0, ptr2 = 0;
        vector<int> pair(2, 0);
        
        while (ptr1 + ptr2 != total / 2 + 1) {
            pair[0] = pair[1];
            
            if (ptr1 != nums1.size() && ptr2 != nums2.size())
                pair[1] = nums1[ptr1] < nums2[ptr2] ? nums1[ptr1++] : nums2[ptr2++];
            else
                pair[1] = ptr1 != nums1.size() ? nums1[ptr1++] : nums2[ptr2++];
        }
        
        return total % 2 ? pair[1] : (pair[0] + pair[1]) / 2.0;
    }
};

