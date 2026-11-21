class Solution {
public:
    int findLucky(vector<int>& arr) {
        const int MASK = 0xFFFF;
        int n = arr.size();

        // Store frequency of value x at index x - 1
        for (int i = 0; i < n; i++) {
            int val = arr[i] & MASK;

            if (val <= n) {
                arr[val - 1] += (1 << 16);
            }
        }

        // Check from largest to smallest
        for (int i = n - 1; i >= 0; i--) {
            int freq = arr[i] >> 16;
            int value = i + 1;

            if (freq == value) {
                return value;
            }
        }

        return -1;
    }
};