class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int bitMask = 0;
        for (char c : allowed) {
            bitMask |= (1 << (c - 'a'));
        }

        int res = words.size();
        for (const string& w : words) {
            for (char c : w) {
                int bit = 1 << (c - 'a');
                if ((bit & bitMask) == 0) {
                    res--;
                    break;
                }
            }
        }

        return res;
    }
};