class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& interval) {
        vector<vector<int>> result;
        int i = 0;
        
        while (i != intervals.size() && intervals[i][0] < interval[0])
            result.push_back(intervals[i++]);
        
        if (result.empty() || result.back()[1] < interval[0]) result.push_back(interval);
        else result.back()[1] = max(result.back()[1], interval[1]);
        
        while (i != intervals.size()) {
            if (result.back()[1] < intervals[i][0]) result.push_back(intervals[i]);
            else result.back()[1] = max(result.back()[1], intervals[i][1]);
            i++;
        }
        
        return result;
    }
};
