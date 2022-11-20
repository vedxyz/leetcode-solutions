class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        
        for (int i = 1; i <= n; i++) {
            result.push_back("");
            
            if (i % 3 == 0)
                result.back() += "Fizz";
            if (i % 5 == 0)
                result.back() += "Buzz";
            if (result.back().empty())
                result.back() += to_string(i);
        }
        
        return result;
    }
};

