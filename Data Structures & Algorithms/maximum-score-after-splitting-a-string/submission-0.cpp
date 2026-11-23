class Solution {
public:
    int maxScore(string s) {
        int c0 = 0, c1 = 0;

        // First split: s[0] | remaining string
        if(s[0] == '0')
            c0 = 1;

        for(int j = 1; j < s.size(); j++) {
            if(s[j] == '1')
                c1++;
        }

        int ans = c0 + c1;

        // Move split towards right
        for(int j = 1; j < s.size() - 1; j++) {
            if(s[j] == '0')
                c0++;
            else
                c1--;

            ans = max(ans, c0 + c1);
        }

        return ans;
    }
};