class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        map<string, int> atomcount;
        stack<map<string, int>> stk;
        int i = 0;
        while (i < n) {
            if (formula[i] == '(') {
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                int j = i + 1;
                int num = 0;
                while (j < n && isdigit(formula[j])) {
                    num = num * 10 + (formula[j] - '0');
                    j++;
                }
                num = (num == 0) ? 1 : num;
                map<string, int> top = stk.top();
                stk.pop();
                for (auto& p : top) {
                    p.second *= num;
                }
                if (stk.empty()) {
                    for (auto &p : top) {
                        atomcount[p.first] += p.second;
                    }
                } else {
                    for (auto &p : top) {
                        stk.top()[p.first] += p.second;
                    }
                }
                i = j;

            } else {
                int j = i + 1;
                while (j < n && islower(formula[j])) {
                    j++;
                }
                string atom = formula.substr(i, j - i);
                i = j;
                int num = 0;
                while (j < n && isdigit(formula[j])) {
                    num = num * 10 + (formula[j] - '0');
                    j++;
                }
                num = (num == 0) ? 1 : num;
                if (stk.empty()) {
                    atomcount[atom] += num;
                } else {
                    stk.top()[atom] += num;
                }
                i = j;
            }
        }
         string ans;
        for (const auto &p : atomcount) {
            ans += p.first;
            if (p.second > 1) {
                ans += to_string(p.second);
            }
        }
        return ans;
    }
};