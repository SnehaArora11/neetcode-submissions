class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(int i =0; i< emails.size(); i++)
        {
            int at = 0;
            int j =0;
            string local ="";
            string domain="";
            while(j< emails[i].size())
            {
                if(emails[i][j]=='@')
                {
                    j++;
                    if(emails[i][j] == '.') continue;
                    while(j< emails[i].size()){
                    domain += emails[i][j];
                    j++;
                    }
                    at =1;
                }
                else if(emails[i][j]=='+' )
                {
                    while(emails[i][j] != '@')j++;
                }
                else if(emails[i][j] == '.') j++;
                else
                {
                    local += emails[i][j];
                    j++;
                }
            }
            s.insert(local+domain);
        }
        return s.size();
    }
};