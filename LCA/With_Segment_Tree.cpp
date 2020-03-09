#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

struct p {
	int node, h;
	bool operator< (const p& a) const {
		return h < a.h;
	}
};

struct ST {
	vector <p> tree;
	int height;
	ST(int n) {
		height = 1 << (int)ceil(log2(n));
		tree.resize(height * 2, p{ 0,(int)1e9 });
	}
	void update(int now, int idx, int val) {
		now += height - 1;
		tree[now] = p{ idx, val };
		while (now >>= 1)
			tree[now] = min(tree[now * 2], tree[now * 2 + 1]);
	}
	p query(int left, int right) {
		p ret = p{ 0, (int)1e9 };
		left += height - 1, right += height - 1;
		for (; left < right; left >>= 1, right >>= 1) {
			if (left & 1)
				ret = min(ret, tree[left++]);
			if (!(right & 1))
				ret = min(ret, tree[right--]);
		}
		if (left == right) ret = min(ret, tree[left]);
		return ret;
	}
	~ST() {
		tree.clear();
	}
};

vvi adj;
vi idx, visit;
int cnt = 1;

void dfs(int now, int level, ST& st) {
	visit[now] = 1;
	if(!idx[now]) idx[now] = cnt;
	st.update(cnt++, now, level);
	for (auto next : adj[now]) {
		if (visit[next]) continue;
		dfs(next, level + 1, st);
		st.update(cnt++, now, level);
	}
	visit[now] = 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	ST st(n * 2 - 1);
	adj = vvi(n + 1);
	visit = idx = vi(n + 1);
	for (int i = 1, a, b; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1, st);
	int m; cin >> m;
	while (m--) {
		int a, b; cin >> a >> b;
		cout << st.query(min(idx[a], idx[b]), max(idx[a], idx[b])).node << '\n';
	}
	return 0;
}
