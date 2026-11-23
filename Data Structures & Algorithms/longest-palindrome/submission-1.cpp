class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> c(128, 0);
        for(auto it: s)c[it - 'A']++;
        int ans =0;
        for(auto ch : c)
        {
            if(ch %2 ==0)ans += ch;
            else if( ch != 0 ) ans += ch-1;
        }
        return ans < s.size()? ans+1: ans;
    }
};