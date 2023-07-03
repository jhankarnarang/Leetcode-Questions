class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        
        if (s == goal) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            
            for (int c : count) {
                if (c > 1) {
                    return true;
                }
            }
            
            return false;
        }
        
        int first = -1;
        int second = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != goal[i]) {
                if (first == -1) {
                    first = i;
                } else if (second == -1) {
                    second = i;
                } else {
                    return false;
                }
            }
        }
        
        return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
    }
};
