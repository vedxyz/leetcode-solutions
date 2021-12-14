class Solution {
public:
     vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        for (int i = 0; i != intervals.size(); i++)
            if (result.empty() || result.back()[1] < intervals[i][0])
                result.push_back(intervals[i]);
            else
                result.back()[1] = max(result.back()[1], intervals[i][1]);
        
        return result;
    }
    
    
    // OR my original solution
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        int i = 0;
        while (i != intervals.size()) {
            vector<int> interval = intervals[i];
            int last = i;
            
            for (int j = i + 1; j != intervals.size(); j++)
                if (interval[1] >= intervals[j][0] && interval[0] <= intervals[j][1]) {
                    interval[1] = max(interval[1], intervals[j][1]);
                    last = j;
                } else if (last == i) break;
            
            result.push_back(interval);
            i = last + 1;
        }
        
        return result;
    }
};

