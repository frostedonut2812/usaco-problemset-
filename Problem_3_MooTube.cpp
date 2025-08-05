#include <bits/stdc++.h>
using namespace std;
#define fast_io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        int ulp_x = find(x);
        int ulp_y = find(y);
        if (ulp_x == ulp_y) return;
        if (size[ulp_x] > size[ulp_y]) {
            parent[ulp_y] = ulp_x;
            size[ulp_x] += size[ulp_y];
        } else {
            parent[ulp_x] = ulp_y;
            size[ulp_y] += size[ulp_x];
        }
    }
};

int32_t main() {
    fast_io;

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int N, Q;
    cin >> N >> Q;
    
    vector<vector<int>> edges;
    for (int i = 0; i < N - 1; i++) {
        int f_v, s_v, k;
        cin >> f_v >> s_v >> k;
        edges.push_back({k, f_v, s_v});
    }
    sort(edges.begin(), edges.end(), greater<vector<int>>());

    vector<tuple<int, int, int>> queries; 
    for (int i = 0; i < Q; i++) {
        int k, v;
        cin >> k >> v;
        queries.push_back({k, v, i});
    }
    sort(queries.rbegin(), queries.rend());

    vector<int> ans(Q);
    DSU dsu(N);
    int edge_ptr = 0;

    for (auto &[k, v, idx] : queries) {
        while (edge_ptr < edges.size() && edges[edge_ptr][0] >= k) {
            int u = edges[edge_ptr][1];
            int w = edges[edge_ptr][2];
            dsu.Union(u, w);
            edge_ptr++;
        }
        ans[idx] = dsu.size[dsu.find(v)] - 1;
    }

    for (int a : ans) cout << a << '\n';
}
