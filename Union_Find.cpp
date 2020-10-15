struct UF {
	int *arr, *sz;
	UF(int n) {
		arr = new int[n + 1];
		sz = new int[n + 1];
		FOR(i, 0, n) arr[i] = i, sz[i] = 1;
	}
	int find(int x) {
		return (arr[x] == x) ? x : arr[x] = find(arr[x]);
	}
	void merge(int a, int b) {
		a = find(a), b = find(b);
		if (sz[a] > sz[b]) swap(a, b);
		arr[a] = b, sz[b] += sz[a];
	}
	~UF() {
		delete[] arr, delete[] sz;
	}
};
