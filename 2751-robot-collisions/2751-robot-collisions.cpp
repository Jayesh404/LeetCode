class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        // Create a vector of pairs to keep track of the original indices
        vector<pair<int, int>> robots;
        for (int i = 0; i < n; ++i) {
            robots.push_back({positions[i], i});
        }

        // Sort robots based on their positions
        sort(robots.begin(), robots.end());

        vector<int> sortedHealths(n);
        string sortedDirections = "";

        // Fill sortedHealths and sortedDirections based on sorted positions
        for (int i = 0; i < n; ++i) {
            sortedHealths[i] = healths[robots[i].second];
            sortedDirections += directions[robots[i].second];
        }

        stack<int> st;

        for (int i = 0; i < n; ++i) {
            if (st.empty() || sortedDirections[st.top()] == sortedDirections[i]) {
                st.push(i);
            } else {
                // Handle collisions
                while (!st.empty() && sortedDirections[st.top()] == 'R' && sortedDirections[i] == 'L') {
                    if (sortedHealths[st.top()] == sortedHealths[i]) {
                        sortedHealths[st.top()] = 0;
                        sortedHealths[i] = 0;
                        st.pop();
                        break;
                    } else if (sortedHealths[st.top()] > sortedHealths[i]) {
                        sortedHealths[st.top()]--;
                        sortedHealths[i] = 0;
                        break;
                    } else {
                        sortedHealths[i]--;
                        sortedHealths[st.top()] = 0;
                        st.pop();
                    }
                }

                if (sortedHealths[i] > 0) {
                    st.push(i);
                }
            }
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            if (sortedHealths[i] > 0) {
                ans[robots[i].second] = sortedHealths[i];
            }
        }

        // Collect results in the original order
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (ans[i] > 0) {
                result.push_back(ans[i]);
            }
        }

        return result;
    }
};

