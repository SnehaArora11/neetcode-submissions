class Solution {
public:
    bool divideArray(vector<int>& nums) {
        bitset<501> bits;

        for (int x : nums) {
            bits[x] = bits[x] ^ 1;
        }

        return bits.none();
    }
};