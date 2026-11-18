class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = *max_element(nums.begin(), nums.end());
        int temp = nums[0];
        for(int i =1; i<nums.size(); i++)
        {
            if(nums[i] > nums[i-1]) temp += nums[i];
            else
            {
                ans = max(temp, ans);
                temp = nums[i];
            }
        }
        return max(ans, temp);
    }
};