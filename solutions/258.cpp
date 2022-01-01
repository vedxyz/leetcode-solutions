class Solution {
public:
    int addDigits(int num) {
        int sum = num;
        while (sum > 9) {
            int newSum = 0;
            while (sum) {
                newSum += sum % 10;
                sum /= 10;
            }
            sum = newSum;
        }
        return sum;
    }
};

