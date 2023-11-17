class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;

        int minMaxPairSum = INT_MIN;
        while (left < right) {
            int currentPairSum = nums[left] + nums[right];
            minMaxPairSum = max(minMaxPairSum, currentPairSum);
            left++;
            right--;
        }
        return minMaxPairSum;
    }
};