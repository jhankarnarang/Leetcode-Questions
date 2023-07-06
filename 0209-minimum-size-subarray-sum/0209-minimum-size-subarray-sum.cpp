class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int minLength = std::numeric_limits<int>::max();

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                minLength = std::min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }

        return (minLength == std::numeric_limits<int>::max()) ? 0 : minLength;
    }
};