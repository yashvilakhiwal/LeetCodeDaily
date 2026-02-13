class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 0;

        for (int mask = 1; mask < 8; mask++) {
            vector<int> active;
            for (int b = 0; b < 3; b++)
                if ((mask >> b) & 1) active.push_back(b);

            if (active.size() == 1) {
                int len = 0;
                for (int i = 0; i < n; i++) {
                    int bit = (s[i]=='a') ? 0 : (s[i]=='b') ? 1 : 2;
                    if (bit == active[0]) len++;
                    else len = 0;
                    ans = max(ans, len);
                }
                continue;
            }

            unordered_map<long long, int> first;
            int ca=0, cb=0, cc=0;

            auto getState = [&]() {
                int cnt[3] = {ca, cb, cc};
                int ref = cnt[active[0]];
                long long st = 0;
                for (int i = 1; i < (int)active.size(); i++)
                    st = st * (2LL*n+1) + (ref - cnt[active[i]] + n);
                return st;
            };

            first[getState()] = -1;

            for (int i = 0; i < n; i++) {
                char ch = s[i];
                int bit = (ch=='a') ? 0 : (ch=='b') ? 1 : 2;

                if (!((mask >> bit) & 1)) {
                    first.clear();
                    ca = cb = cc = 0;
                    first[getState()] = i;
                } else {
                    if (ch=='a') ca++;
                    else if (ch=='b') cb++;
                    else cc++;

                    long long st = getState();
                    auto it = first.find(st);
                    if (it != first.end())
                        ans = max(ans, i - it->second);
                    else
                        first[st] = i;
                }
            }
        }
        return ans;
    }
};