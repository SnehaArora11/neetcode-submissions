class Solution {
public:
    string largestGoodInteger(string num) {
        vector<string> temp;
        
        int i = 0, j = 2;

        while(j < num.size()) {
            if(num[i] == num[j] && num[i+1] == num[j]) {
                temp.push_back(num.substr(i, 3));
            }

            i++;
            j++;
        }

        if(temp.empty())
            return "";

        string mx = temp[0];

        for(int i = 1; i < temp.size(); i++) {
            if(temp[i] > mx) {
                mx = temp[i];
            }
        }

        return mx;
    }
};