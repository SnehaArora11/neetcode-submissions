class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int c =0;
        int i =1, j=0;
        while(i < 2*n && j< i)
        {
            if(nums[i%n] < nums[j%n]) c++;
            j++;i++;
        }
        return c <= 2;
    }
};