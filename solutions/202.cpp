class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> sums({n});
        int sum = n;
        
        while (sum != 1) {
            int newSum = 0;
            while (sum) {
                newSum += pow(sum % 10, 2);
                sum /= 10;
            }
            sum = newSum;
            
            if (sums.count(sum)) return false;
            sums.insert(sum);
        }
        return true;
    }
};

