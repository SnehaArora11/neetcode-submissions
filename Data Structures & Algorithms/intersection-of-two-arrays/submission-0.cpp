class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        for(auto it : nums1)s.insert(it);
        set<int> ans;
        for(auto it : nums2)
        {
            if(s.find(it)!=s.end())ans.insert(it);
        }
       return vector<int>(ans.begin(), ans.end());
    }
};