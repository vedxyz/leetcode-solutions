class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mins(amount + 1, INT_MAX);
        mins[0] = 0;
        
        for (int i = 1; i <= amount; i++)
            for (int j = 0; j != coins.size(); j++)
                if (i - coins[j] >= 0 && mins[i - coins[j]] != INT_MAX)
                    mins[i] = min(mins[i], mins[i - coins[j]] + 1);
        
        return mins[amount] != INT_MAX ? mins[amount] : -1;
    }
};

