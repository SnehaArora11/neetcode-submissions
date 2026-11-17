class Solution {
public:
    int maxDifference(string s) {
        vector<int> c(26,0);
        for(auto ch : s)
        {
            c[ch-'a']++;
        }
        int oddMax = 0, evenMin = s.length();
        for (int c : c) {
            if (c & 1) {
                oddMax = max(oddMax, c);
            } else if (c > 0) {
                evenMin = min(evenMin, c);
            }
        }

        return oddMax - evenMin;
    }
    
};