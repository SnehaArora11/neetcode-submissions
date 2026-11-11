class Solution {
public:
    int converttoint(string s)
    {
        return stoi(s);
    }
    int countSeniors(vector<string>& d) {
        int ans =0;
        for(int i =0; i< d.size(); i++)
        {
            string s = d[i].substr(11, 2);
            int age = converttoint(s);
            if(age > 60) ans ++;
        }
        return ans;
    }
};