class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry = k;
        
        for (int i = num.size() - 1; i >= 0; i--) {
            num[i] += carry;
            carry = num[i] > 9 ? num[i] / 10 : 0;
            num[i] %= 10;
            
            if (carry == 0) break;
        }
        
        while (carry) {
            num.insert(num.begin(), carry % 10);
            carry /= 10;
        }
        
        return num;
    }
};

