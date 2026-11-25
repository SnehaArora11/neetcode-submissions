class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int N = nums.size();
        // a ^ a = 0
        // xorr = (1 ^ 2 ^ ... N) ^ (nums[0] ^ nums[1] ^ ... nums[N - 1])
        // xorr = missing ^ duplicate
        int xorr = 0;
        for (int i = 1; i <= N; i++) {
            xorr ^= i;
            xorr ^= nums[i - 1];
        }

        // bit that is set in only one number among (duplicate, missing),
        // will be set in (duplicate ^ missing)
        // take rightMost set bit for simplicity
        int rightMostBit = xorr & ~(xorr - 1);

        // divide numbers (from nums, from [1, N]) into two sets w.r.t the rightMostBit
        // xorr the numbers of these sets independently
        int x = 0, y = 0;
        for (int i = 1; i <= N; i++) {
            if (i & rightMostBit) {
                x ^= i;
            } else {
                y ^= i;
            }

            if (nums[i - 1] & rightMostBit) {
                x ^= nums[i - 1];
            } else {
                y ^= nums[i - 1];
            }
        }

        // identify the duplicate number from x and y
        for (int num : nums) {
            if (num == x) {
                return {x, y};
            }
        }
        return {y, x};
    }
};