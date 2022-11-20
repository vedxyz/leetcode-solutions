class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u',
                                    'A', 'E', 'I', 'O', 'U'});
        
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (vowels.find(s[left]) == vowels.end() && left < right)
                left++;
            while (vowels.find(s[right]) == vowels.end() && left < right)
                right--;
            if (left < right) {
                char temp = s[left];
                s[left++] = s[right];
                s[right--] = temp;
            }
        }
        return s;
    }
};

