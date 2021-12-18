// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool bad = isBadVersion(mid);
            
            if (bad && (mid - 1 < 1 || !isBadVersion(mid - 1))) 
                return mid;
            
            if (bad) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};

