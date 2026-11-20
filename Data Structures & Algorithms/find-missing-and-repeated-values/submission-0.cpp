class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& mat) {
        int n = mat.size();
        int N = n * n;

        int xr = 0;

        // XOR all matrix values
        for (auto& row : mat) {
            for (int x : row) {
                xr ^= x;
            }
        }

        // XOR with expected values 1...n^2
        for (int i = 1; i <= N; i++) {
            xr ^= i;
        }

        // xr = missing ^ repeated

        // Find rightmost different bit
        int bit = xr & -xr;

        int a = 0, b = 0;

        // Divide matrix values into two groups
        for (auto& row : mat) {
            for (int x : row) {
                if (x & bit)
                    a ^= x;
                else
                    b ^= x;
            }
        }

        // Divide expected values into same two groups
        for (int i = 1; i <= N; i++) {
            if (i & bit)
                a ^= i;
            else
                b ^= i;
        }

        // a and b are duplicate/missing.
        // Find which one is duplicate.
        for (auto& row : mat) {
            for (int x : row) {
                if (x == a)
                    return {a, b};
            }
        }

        return {b, a};
    }
};