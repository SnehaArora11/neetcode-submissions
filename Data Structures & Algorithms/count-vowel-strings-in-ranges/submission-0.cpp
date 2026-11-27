class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& q) {

        vector<int> p;

        for (auto it : words) {
            int n = it.size();

            if (isVowel(it[0]) && isVowel(it[n - 1]))
                p.push_back(1);
            else
                p.push_back(0);
        }

        // prefix sum
        for (int i = 1; i < p.size(); i++) {
            p[i] += p[i - 1];
        }

        vector<int> sol;

        for (int i = 0; i < q.size(); i++) {

            int left = q[i][0];
            int right = q[i][1];

            if (left == 0)
                sol.push_back(p[right]);
            else
                sol.push_back(p[right] - p[left - 1]);
        }

        return sol;
    }
};