class Solution {
public:
    int maxProductDifference(std::vector<int>& nums) {
        int smallest1 = INT_MAX, smallest2 = INT_MAX;
        int largest1 = INT_MIN, largest2 = INT_MIN;

        for (int num : nums) {
            if (num <= smallest1) {
                smallest2 = smallest1;
                smallest1 = num;
            } else if (num <= smallest2) {
                smallest2 = num;
            }

            if (num >= largest1) {
                largest2 = largest1;
                largest1 = num;
            } else if (num >= largest2) {
                largest2 = num;
            }
        }

        return (largest1 * largest2) - (smallest1 * smallest2);
    }
};
