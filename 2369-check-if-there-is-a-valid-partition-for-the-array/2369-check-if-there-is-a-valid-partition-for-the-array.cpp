class Solution {
public:
    unordered_map<int, bool> memo;

    bool prefixIsValid(vector<int>& nums, int i) {
        if (memo.count(i)) {
            return memo[i];
        }
        bool ans = false;

        if (i > 0 && nums[i] == nums[i - 1]) {
            ans |= prefixIsValid(nums, i - 2);
        }
        if (i > 1 && nums[i] == nums[i - 1] && nums[i - 1] == nums[i - 2]) {
            ans |= prefixIsValid(nums, i - 3);
        }
        if (i > 1 && nums[i] == nums[i - 1] + 1 && nums[i - 1] == nums[i - 2] + 1) {
            ans |= prefixIsValid(nums, i - 3);
        }
        memo[i] = ans;
        return ans;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        memo[-1] = true;

        return prefixIsValid(nums, n - 1);
    }
};