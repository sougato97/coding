// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t){
            return true;
        }
        return false;
    }
};
