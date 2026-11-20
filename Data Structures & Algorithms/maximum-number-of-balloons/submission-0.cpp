class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> c(26, 0);

        for (char s : text)
            c[s - 'a']++;

        int m = INT_MAX;
        string b = "balon";   // unique characters only

        for (char ch : b) {
            if (ch == 'l' || ch == 'o')
                m = min(m, c[ch - 'a'] / 2);
            else
                m = min(m, c[ch - 'a']);
        }

        return m;
    }
};