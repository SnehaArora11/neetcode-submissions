class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> source;

        for(auto& it : paths) {
            source.insert(it[0]);
        }

        for(auto& it : paths) {
            if(source.find(it[1]) == source.end())
                return it[1];
        }

        return "";
    }
};