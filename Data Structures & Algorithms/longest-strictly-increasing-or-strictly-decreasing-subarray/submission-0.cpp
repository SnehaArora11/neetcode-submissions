class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        int inc = 0;
        int dec = 0;

        for (int right = 1; right < n; right++) {

            // Increasing sequence broke
            if (nums[right] <= nums[right - 1])
                inc = right;

            // Decreasing sequence broke
            if (nums[right] >= nums[right - 1])
                dec = right;

            ans = max(ans, right - inc + 1);
            ans = max(ans, right - dec + 1);
        }

        return ans;
    }
};