class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (auto stu : students)
            q.push(stu);

        stack<int> stk;
        for (int i = sandwiches.size() - 1; i >= 0; i--)
            stk.push(sandwiches[i]);

        int attempts = 0;
        while (!q.empty() && attempts < q.size()) {
            if (q.front() == stk.top()) {
                q.pop();
                stk.pop();
                attempts = 0;
            } else {
                q.push(q.front());
                q.pop();
                attempts++;
            }
        }
        return q.size();
    }
};
