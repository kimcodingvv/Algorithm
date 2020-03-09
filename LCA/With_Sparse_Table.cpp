#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX ((int)log2(n))

typedef vector <int> vi;
typedef vector <vi> vvi;

vvi par, adj;
vi depth,visit;
int n, m;

void dfs(int now, int level) {
	depth[now] = level;
	for (auto next : adj[now]) {
		if (depth[next]) continue;
		dfs(next, level + 1);
		par[next][0] = now;
	}
}

int LCA(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	int diff = depth[a] - depth[b];
	for (int i = 0; i <= MAX; i++)
		if (diff & (1 << i)) a = par[a][i];
	if (a != b) {
		for (int i = MAX; i >= 0; i--) {
			if (par[a][i] && par[a][i] != par[b][i]) {
				a = par[a][i];
				b = par[b][i];
			}
		}
		a = par[a][0];
	}
	return a;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	par = vvi(n + 1, vi(MAX + 1));
	adj = vvi(n + 1);
	depth = vi(n + 1);
	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	for (int i = 1; i <= MAX; i++)
		for (int j = 1; j <= n; j++)
			par[j][i] = par[par[j][i - 1]][i - 1];
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}
	return 0;
}
