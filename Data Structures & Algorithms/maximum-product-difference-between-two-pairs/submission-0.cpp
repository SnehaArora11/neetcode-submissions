class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        auto max1 = max_element(nums.begin(), nums.end());
        int a = *max1;
        *max1 = INT_MIN;

        auto max2 = max_element(nums.begin(), nums.end());
        int b = *max2;

        *max1 = a;  // restore

        auto min1 = min_element(nums.begin(), nums.end());
        int c = *min1;
        *min1 = INT_MAX;

        auto min2 = min_element(nums.begin(), nums.end());
        int d = *min2;

        *min1 = c;  // restore

        return a * b - c * d;
    }
};