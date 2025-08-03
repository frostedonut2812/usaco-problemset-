#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

int32_t main() {
    fast_io;

    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    vector<pair<int, int>> v;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({y, x}); 
    }

    sort(v.begin(), v.end()); 

    int ans = 0;
    int start = 0;
    int end = v.size() - 1;

    while (start < end) {
        int min_index = min(v[start].second, v[end].second);
        v[start].second -= min_index;
        v[end].second -= min_index;
        ans = max(ans, v[start].first + v[end].first);

        if (v[start].second == 0) start++;
        if (v[end].second == 0) end--;
    }

    if (start == end) {
        if (v[start].second == 1) {
            ans = max(ans, v[start].first);
        } else {
            ans = max(ans, v[start].first * 2);
        }
    }

    cout << ans << '\n';

    return 0;
}
