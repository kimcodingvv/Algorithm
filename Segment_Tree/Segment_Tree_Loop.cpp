struct ST {
	int* tree, leaf;
	ST(int n) {
		leaf = (1 << (int)ceil(log2(n)));
		tree = new int[leaf * 2]();
	}
	void update(int idx, int val) {
		idx += leaf;
		tree[idx] = val;
		while (idx >>= 1) tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
	}
	int query(int l, int r) {
		int ret = 0;
		l += leaf, r += leaf;
		for (; l <= r; l >>= 1, r >>= 1) {
			if (l & 1) ret += tree[l++];
			if (~r & 1) ret += tree[r--];
		}
		if (l == r) ret += tree[l];
		return ret;
	}
	~ST() {
		delete[] tree;
	}
};
