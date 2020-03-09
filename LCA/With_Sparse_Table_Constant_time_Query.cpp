#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define vi vector <int>
#define vvi vector <vi>
#define eb emplace_back
using namespace std;

int main() {
	FIO;
	int n; cin >> n;
	vvi adj(n + 1);
	FOR(i, 1, n - 1) {
		int a, b; cin >> a >> b;
		adj[a].eb(b);
		adj[b].eb(a);
	}
	vi euler(1), idx(n + 1);
	vvi Min(2 * n + 1, vi(18, 1e9));
	int cnt = 0;
	function <void(int, int)> dfs = [&](int now, int par) {
		Min[euler.size()][0] = idx[now] = ++cnt;
		euler.eb(now);
		for (int next : adj[now]) {
			if (par == next) continue;
			dfs(next, now);
			Min[euler.size()][0] = idx[now];
			euler.eb(now); cnt++;
		}
	};
	dfs(1, 0);
	FOR(j, 1, 17) FOR(i, 1, 2 * n)
		if(i + (1 << j) <= 2 * n)
			Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
	auto RMQ = [&](int a, int b) {
		int x = min(idx[a], idx[b]);
		int y = max(idx[a], idx[b]);
		int l = (int)log2(y - x + 1);
		return euler[min(Min[x][l], Min[y - (1 << l) + 1][l])];
	};
	int m; cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		cout << RMQ(a, b) << '\n';
	}
	return 0;
}
