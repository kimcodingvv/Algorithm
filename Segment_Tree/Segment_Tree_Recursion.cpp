struct ST {
	int* tree;
	ST(int n) {
		int tree_size = 1 << ((int)ceil(log2(n)) + 1);
		tree = new int[tree_size]();
	}
	void update(int now, int start, int end, int idx, int val) {
		if (idx < start || end < idx) return;
		if (start == end) tree[now] = val;
		else {
			int mid = (start + end) / 2;
			update(now * 2, start, mid, idx, val);
			update(now * 2 + 1, mid + 1, end, idx, val);
			tree[now] = tree[now * 2] + tree[now * 2 + 1];
		}
	}
	int query(int now, int start, int end, int left, int right) {
		if (end < left || right < start) return 0;
		if (left <= start && end <= right) return tree[now];
		int mid = (start + end) / 2;
		return query(now * 2, start, mid, left, right) + query(now * 2 + 1, mid + 1, end, left, right);
	}
	~ST() {
		delete[] tree;
	}
}
