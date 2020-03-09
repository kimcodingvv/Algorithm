struct LST {
	int* tree, * lazy;
	int size;
	LST(int n) {
		size = (1 << (int)(ceil(log2(n)) + 1));
		tree = new int[size]();
		lazy = new int[size]();
	}
	void propagate(int now, int start, int end) {
		if (!lazy[now]) return;
		tree[now] += lazy[now] * (end - start + 1);
		if (start < end) {
			lazy[now * 2] += lazy[now];
			lazy[now * 2 + 1] += lazy[now];
		}
		lazy[now] = 0;
	}
	void update(int now, int start, int end, int left, int right, int val) {
		propagate(now, start, end);
		if (right < start || end < left) return;
		if (left <= start && end <= right) {
			lazy[now] += val;
			propagate(now, start, end);
			return;
		}
		int mid = (start + end) / 2;
		update(now * 2, start, mid, left, right, val);
		update(now * 2 + 1, mid + 1, end, left, right, val);
		tree[now] = tree[now * 2] + tree[now * 2 + 1];
	}
	int query(int now, int start, int end, int left, int right) {
		propagate(now, start, end);
		if (right < start || end < left) return 0;
		if (left <= start && end <= right) return tree[now];
		int mid = (start + end) / 2;
		return query(now * 2, start, mid, left, right) + query(now * 2 + 1, mid + 1, end, left, right);
	}
	~LST() {
		delete[] tree;
		delete[] lazy;
	}
};
