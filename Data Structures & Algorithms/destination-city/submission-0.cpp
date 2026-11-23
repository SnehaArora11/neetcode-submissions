class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> r;
        for(auto it : paths)
        {
            r[it[0]] = it[1];
        }
        for(auto it : paths)
        {
            if(r.find(it[0])==r.end())return it[0];
             if(r.find(it[1])==r.end())return it[1];
        }
        return "";
    }
};
