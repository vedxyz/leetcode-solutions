class Solution {
public:
    int fib(int n) {
        vector<int> last2({0, 1});
        
        for (int i = 0; i < n - 1; i++) {
            int next = last2[0] + last2[1];
            last2[0] = last2[1];
            last2[1] = next;
        }
        
        return n ? last2[1] : 0;
    }
};

