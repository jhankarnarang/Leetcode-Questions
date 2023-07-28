class Solution {
private:
    std::vector<std::vector<int>> memo;

    int maxDiff(std::vector<int>& nums, int left, int right, int n) {
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        if (left == right) {
            return nums[left];
        }

        int scoreByLeft = nums[left] - maxDiff(nums, left + 1, right, n);
        int scoreByRight = nums[right] - maxDiff(nums, left, right - 1, n);
        memo[left][right] = std::max(scoreByLeft, scoreByRight);

        return memo[left][right];
    }

public:
    bool PredictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        memo.resize(n, std::vector<int>(n, -1));

        return maxDiff(nums, 0, n - 1, n) >= 0;
    }
};