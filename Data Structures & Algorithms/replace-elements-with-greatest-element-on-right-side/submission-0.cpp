class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int g = arr[n-1];
        vector<int> ans(n);
        ans[n-1]=-1;
        for(int i = n-2; i>=0 ;i-- )
        {
            int temp = arr[i];
            ans[i]= g;
            g = temp>g?temp:g;
        }
        return ans;
    }
};