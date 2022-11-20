class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0, min = prices[0];
        
        for (int i = 0; i != prices.size(); i++) {
            if (min > prices[i])
                min = prices[i];
            
            if (max < prices[i] - min)
                max = prices[i] - min;
        }
        
        return max;
    }
};
