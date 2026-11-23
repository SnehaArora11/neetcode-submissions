class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> c(26,0);
        for(auto it: chars)c[it-'a']++;

        
        int ans = 0;
        for(auto it : words)
        {
            vector<int> temp(c.begin(), c.end());
            int flag = 0;
            for( auto c : it )
            {
                if(temp[c-'a']==0){
                    flag = 1;
                    break;
                }
                temp[c-'a']--;
            }
            if(!flag)
            ans += it.size();
        }
        return ans;
    }
};