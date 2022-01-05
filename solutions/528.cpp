class Solution {
    vector<int> prob;
public:
    Solution(vector<int>& w) : prob({w[0]}) {
        for (int i = 1; i != w.size(); i++)
            prob.push_back(w[i] + prob.back());
    }
    
    int pickIndex() {
        float randN = ((float) rand() / RAND_MAX) * prob.back();
        
        int low = 0, high = prob.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if ((mid - 1 < 0 || prob[mid - 1] <= randN) && randN < prob[mid])
                return mid;
            else if (prob[mid] <= randN)
                low = mid + 1;
            else high = mid - 1;
        }
        
        return prob.size() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

