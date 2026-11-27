class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> q;

        for (int i = 0; i < tickets.size(); i++) {
            if (i == k)
                q.push(-tickets[i]);   // mark kth person
            else
                q.push(tickets[i]);
        }

        int time = 0;

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            time++;   // buying one ticket always takes 1 second

            if (top < 0) {
                top++;              // e.g. -3 -> -2

                if (top == 0)
                    return time;     // kth person finished

                q.push(top);
            }
            else {
                top--;

                if (top > 0)
                    q.push(top);
            }
        }

        return time;
    }
};