class Solution {
public:
    bool even(int n)
    {
        return n%2 == 0;
    }
    bool odd(int n)
    {
        return !(n%2==0);
    }
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size()==1)return true;
        int i =1, j=0;
        while(i< nums.size() && j< i)
        {
            if( even(nums[i])&& even(nums[j]))return false;
            if( odd(nums[i])&& odd(nums[j])) return false;
        i++; j++;
        }
        return true;
    }
};