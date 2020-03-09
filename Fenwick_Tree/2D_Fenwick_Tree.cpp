struct FT {
	vvi tree;
	int tree_size;
	FT(int n) : tree_size(n) {
		tree = vvi(n + 1, vi(n + 1));
	}
	void update(int i, int x, int diff) {
		while (i <= tree_size) {
			int j = x;
			while (j <= tree_size) {
				tree[i][j] += diff;
				j += j & -j;
			}
			i += i & -i;
		}
	}
	int sum(int i, int x) {
		int ans = 0;
		while (i) {
			int j = x;
			while (j) {
				ans += tree[i][j];
				j -= j & -j;
			}
			i -= i & -i;
		}
		return ans;
	}
	int query(int a, int b, int c, int d) {
		return sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1);
	}
};
