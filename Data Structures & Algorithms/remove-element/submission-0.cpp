class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i =0,c =0;
        while(i < nums.size()-c)
        {
            if(nums[i]== val)
            {
                for(int j = i ; j< nums.size()-c-1; j++)
                {
                    swap(nums[j], nums[j+1]);
                }
                c ++;
            }
            else
            i++;
        }
        return nums.size()-c;
    }
};