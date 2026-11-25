class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;

        for (int student : students) {
            q.push(student);
        }

        int j = 0;
        int count = 0;

        while (!q.empty()) {
            int student = q.front();
            q.pop();

            if (student == sandwiches[j]) {
                // Sandwich is taken
                j++;
                count = 0;
            } 
            else {
                // Student moves to the back
                q.push(student);
                count++;

                // Every remaining student rejected this sandwich
                if (count == q.size()) {
                    return q.size();
                }
            }
        }

        return 0;
    }
};