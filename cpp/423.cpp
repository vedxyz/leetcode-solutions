// Digit counting could be more elegant/efficient, but good enough.
class Solution {
public:
    string originalDigits(string s) {
        vector<int> chars('z' + 1, 0);
        for (int i = 0; i != s.size(); i++)
            chars[s[i]]++;
        
        vector<int> digitCount(10, 0);
        bool empty = false;
        while (!empty) {
            empty = true;
            if (chars['z'] && chars['e'] && chars['r'] && chars['o']) {
                chars['z']--; chars['e']--; chars['r']--; chars['o']--;
                digitCount[0]++; empty = false;
            } else if (chars['t'] && chars['w'] && chars['o']) {
                chars['t']--; chars['w']--; chars['o']--;
                digitCount[2]++; empty = false;
            } else if (chars['f'] && chars['o'] && chars['u'] && chars['r']) {
                chars['f']--; chars['o']--; chars['u']--; chars['r']--;
                digitCount[4]++; empty = false;
            } else if (chars['s'] && chars['i'] && chars['x']) {
                chars['s']--; chars['i']--; chars['x']--;
                digitCount[6]++; empty = false;
            } else if (chars['e'] && chars['i'] && chars['g'] && chars['h'] && chars['t']) {
                chars['e']--; chars['i']--; chars['g']--; chars['h']--; chars['t']--;
                digitCount[8]++; empty = false;
            } else if (chars['t'] && chars['h'] && chars['r'] && chars['e'] > 1) {
                chars['t']--; chars['h']--; chars['r']--; chars['e']--; chars['e']--;
                digitCount[3]++; empty = false;
            } else if (chars['f'] && chars['i'] && chars['v'] && chars['e']) {
                chars['f']--; chars['i']--; chars['v']--; chars['e']--;
                digitCount[5]++; empty = false;
            } else if (chars['s'] && chars['e'] > 1 && chars['v'] && chars['n']) {
                chars['s']--; chars['e']--; chars['v']--; chars['e']--; chars['n']--;
                digitCount[7]++; empty = false;
            } else if (chars['n'] > 1 && chars['i'] && chars['e']) {
                chars['n']--; chars['i']--; chars['n']--; chars['e']--;
                digitCount[9]++; empty = false;
            } else if (chars['o'] && chars['n'] && chars['e']) {
                chars['o']--; chars['n']--; chars['e']--;
                digitCount[1]++; empty = false;
            }
        }
        
        string result = "";
        for (int i = 0; i != digitCount.size(); i++)
            for (int j = 0; j != digitCount[i]; j++)
                result += to_string(i);
        return result;
    }
};

