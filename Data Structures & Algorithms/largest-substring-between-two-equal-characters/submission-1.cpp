class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int firstIdx[26];
        fill(begin(firstIdx), end(firstIdx), -1);
        int res = -1;

        for (int i = 0; i < s.size(); i++) {
            int j = s[i] - 'a';
            if (firstIdx[j] != -1) {
                res = max(res, i - firstIdx[j] - 1);
            } else {
                firstIdx[j] = i;
            }
        }

        return res;
    }
};