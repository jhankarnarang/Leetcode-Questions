class Solution {
public:
    unordered_map<int, int> mark;
    int dp[2001][2001];

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        for (int i = 0 ; i < n; i++) {
            mark[stones[i]] = i;
        }
        
        dp[0][0] = 1;
        for (int index = 0; index < n; index++) {
            for (int prevJump = 0; prevJump <= n; prevJump++) {
                if (dp[index][prevJump]) {
                    if (mark[stones[index] + prevJump]) {
                        dp[mark[stones[index] + prevJump]][prevJump] = 1;
                    }
                    if (mark[stones[index] + prevJump + 1]) {
                        dp[mark[stones[index] + prevJump + 1]][prevJump + 1] = 1;
                    }
                    if (mark[stones[index] + prevJump - 1]) {
                        dp[mark[stones[index] + prevJump - 1]][prevJump - 1] = 1;
                    }
                }
                
                
            }
        }

        for (int prevJump = 0; prevJump <= n; prevJump++) {
            if (dp[n - 1][prevJump]) {
                return true;
            }
        }
        return false;
    }
};