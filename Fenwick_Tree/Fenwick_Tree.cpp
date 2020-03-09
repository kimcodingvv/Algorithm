struct FT {
	vector <int> tree;
	FT() {
		tree.resize(MAX * 2 + 1);
	}
	void update(int idx, int diff) {
		while (idx < tree.size()) {
			tree[idx] += diff;
			idx += (idx & -idx);
		}
	}
	int query(int idx) {
		int ans = 0;
		while (idx) {
			ans += tree[idx];
			idx -= (idx & -idx);
		}
		return ans;
	}
};
