class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> totalMin(cost.size() + 1, 0);
        totalMin[1] = cost[0];
        
        for (int i = 2; i != totalMin.size(); i++)
            totalMin[i] = min(totalMin[i - 1], totalMin[i - 2]) + cost[i - 1];
        
        return min(totalMin[totalMin.size() - 1], totalMin[totalMin.size() - 2]);
    }
};

