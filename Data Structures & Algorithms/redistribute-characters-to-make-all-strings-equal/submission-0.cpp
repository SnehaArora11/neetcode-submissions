class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> c(26,0);
        for(auto it : words)
        {
            for(auto ch: it)c[ch-'a']++;
        }
       for(int count : c) {
            if(count % words.size() != 0)
                return false;
        }

        return true;
    }
};