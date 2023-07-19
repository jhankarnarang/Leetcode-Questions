class Solution {
public:
    bool isSubsequence(string s, string t) {      
        int a=0;
        for(char c:t)
        {
            if(s[a]==c) a++;
        }
        if(a==s.size())
            return 1;
        return 0;
    }
};