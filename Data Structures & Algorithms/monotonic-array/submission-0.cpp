class Solution {
public:
    bool inc(vector<int>& nums)
    {
        int i =0, j= 1;
        while(j < nums.size())
        {
            if(nums[i] > nums[j]) return false;
            i++; j++;
        }
        return true;
    }
    bool decr(vector<int>& nums)
    {
        int i =0, j= 1;
        while(j < nums.size())
        {
            if(nums[i] < nums[j]) return false;
            i++; j++;
        }
        return true;
    }
    
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[0] <= nums[1]) return inc(nums);
        return decr(nums);
    }
};