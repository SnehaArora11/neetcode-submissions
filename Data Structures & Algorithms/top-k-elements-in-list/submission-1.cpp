class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // 1. Count frequency
        for (int num : nums) {
            mp[num]++;
        }

        // 2. index = frequency
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto it : mp) {
            bucket[it.second].push_back(it.first);
        }

        // 3. Start from highest frequency
        vector<int> ans;

        for (int freq = nums.size(); freq > 0; freq--) {

            for (int num : bucket[freq]) {
                ans.push_back(num);

                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};