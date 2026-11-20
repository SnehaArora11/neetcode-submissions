class Solution {
public:
    bool wordPattern(string p, string s) {
        unordered_map<string, char> m1;
        unordered_map<char, string> m2;

        string temp = "";
        int j = 0;

        // Add a space so the last word also gets processed
        s += ' ';

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == ' ') {

                // More words than pattern characters
                if (j >= p.size())
                    return false;

                // word already mapped to a different character
                if (m1.count(temp) && m1[temp] != p[j])
                    return false;

                // character already mapped to a different word
                if (m2.count(p[j]) && m2[p[j]] != temp)
                    return false;

                m1[temp] = p[j];
                m2[p[j]] = temp;

                j++;
                temp = "";
            }
            else {
                temp += s[i];
            }
        }

        // fewer words than pattern characters
        return j == p.size();
    }
};