class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int t = accumulate(nums.begin(), nums.end(),0);
       int l =0;
       for(int i =0; i< nums.size(); i++)
       {
        int r = t-l- nums[i];
        if(l==r)return i;
        l += nums[i];
       }
       return -1;
    }
};