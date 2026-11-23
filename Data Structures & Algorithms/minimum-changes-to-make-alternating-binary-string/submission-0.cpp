class Solution {
public:
    int even(string s)
    {
        int ans =0;
        for(int i =0; i< s.size(); i++)
        {
            if(i%2==0 && s[i]!='0')ans++;
            if(i%2 !=0 && s[i]!='1')ans++;
        }
        return ans;
    }
    int odd(string s)
    {
        int ans =0;
        for(int i =0; i< s.size(); i++)
        {
            if(i%2==0 && s[i]=='0')ans++;
            if(i%2 !=0 && s[i]=='1')ans++;
        }
        return ans;
    }

    int minOperations(string s) {
       return min(odd(s), even(s));
    }
};