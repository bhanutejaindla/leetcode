class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        vector<pair<int, pair<int, char>>> v;
        int n = positions.size();

        for (int i = 0; i < n; ++i) {
            v.push_back({positions[i], {healths[i], directions[i]}});
        }

        sort(v.begin(), v.end());
        stack<pair<int, pair<int, char>>> st;

        for (int i = 0; i < v.size(); ++i) {

        while(!st.empty() && ((st.top().second.second == 'R' &&
                                 v[i].second.second == 'L'))) {
                int a = st.top().second.first;
                int b = v[i].second.first;
                if (a > b) {
                    st.top().second.first = a - 1;
                    v[i].second.first = 0;
                    break;
                } else if (b > a) {
                    st.pop();
                    v[i].second.first = b - 1;
                } else {
                    st.pop();
                      v[i].second.first = 0;
                    break;
                }
            }
                if (v[i].second.first > 0) {
                    st.push(v[i]);
                }
            }

            vector<int> result;
            unordered_map<int, int> mp;
            while (!st.empty()) {
                int a = st.top().first;
                int b = st.top().second.first;
                mp[a] = b;
                st.pop();
            }
            for (int i = 0; i < n; i++) {
                if (mp.find(positions[i]) != mp.end()) {
                    result.push_back(mp[positions[i]]);
                }
            }
            return result;
        }
    };